#include <cstdio>
#include <vector>
#include <unordered_map>
#include <chrono>
using namespace std;

struct custom_hash {
    typedef long long ll;
    typedef unsigned long long ull;
    const ull FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    static ull splitmix64(ull x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(ll x) const {
        return splitmix64(x + FIXED_RANDOM);
    }
    size_t operator()(const pair<int,int> &i)const{
        return splitmix64((((ll)i.first)^(((ll)i.second)<<32))+FIXED_RANDOM);
    }
};


const int MOD=998244353;
const int disc_root=3;

int n,m,q;
unordered_map<int,int,custom_hash> white;
vector<int> ones;
vector<int> twos;
int red[5];
int peri[300005];
long long ans[300005];
long long factorial[300005]; ///precomp this
long long fac_inv[300005];

vector<long long> singles,doubles,res;

inline long long qexp(long long b, long long p){
    long long res=1;
    while (p){
        if (p&1) res=(res*b)%MOD;
        b=(b*b)%MOD;
        p>>=1;
    }
    return res;
}

inline long long inv(int i){
    return qexp(i,MOD-2);
}

inline long long nCk (int n,int k){
    return (factorial[n]*fac_inv[k]%MOD)*fac_inv[n-k]%MOD;
}

long long NTT_coeff[2][20];
void NTT(vector<long long> &v, bool flag){
    if (v.size()==1) return;
    vector<long long> even;
    vector<long long> odd;
    even.reserve((v.size())>>1),odd.reserve((v.size())>>1);
    for (int x=0;x<v.size();x++){
        if (x&1) odd.push_back(v[x]);
        else even.push_back(v[x]);
    }
    NTT(even,flag);
    NTT(odd,flag);
    
    long long w=1,wn;
    if (flag) wn=NTT_coeff[0][__builtin_ctz(v.size())];
    else wn=NTT_coeff[1][__builtin_ctz(v.size())];
    for (int x=0;x<(v.size()>>1);x++){
        v[x]=(even[x]+w*odd[x])%MOD;
        w=(w*wn)%MOD;
    }
    for (int x=0;x<(v.size()>>1);x++){
        v[x+(v.size()>>1)]=(even[x]+w*odd[x])%MOD;
        w=(w*wn)%MOD;
    }
}

vector<long long> mul(vector<long long> pa, vector<long long> pb){
    int length=1<<(32-__builtin_clz(pa.size()+pb.size()-2));
    pa.insert(pa.end(),length-pa.size(),0);
    pb.insert(pb.end(),length-pb.size(),0);
    
    vector<long long> pc;
    NTT(pa,true);
    NTT(pb,true);

    int __inv=inv(length);
    for (int x=0;x<length;x++){
        pc.push_back((pa[x]*pb[x]%MOD)*__inv%MOD);
    }
    NTT(pc,false);
    return pc;
}

int main(){
    scanf("%d%d",&n,&m);
    int temp;
    for (int x=0;x<n;x++){
        scanf("%d",&temp);
        white[temp]++;
    }
    
    for (auto &it:white){
        if (it.second==1) ones.push_back(it.first);
        else twos.push_back(it.first);
    }
    
    for (int x=0;x<m;x++){
        scanf("%d",&red[x]);
    }
    
    scanf("%d",&q);
    for (int x=0;x<q;x++){
        scanf("%d",&peri[x]);
        peri[x]>>=1;
        peri[x]--;
    }
    
    fac_inv[0]=factorial[0]=1;
    for (int x=1;x<300005;x++){
        factorial[x]=(factorial[x-1]*x)%MOD;
        fac_inv[x]=inv(factorial[x]);
    }
    
    for (int x=0;x<20;x++){
        NTT_coeff[0][x]=qexp(disc_root,(MOD-1)>>x);
        NTT_coeff[1][x]=inv(NTT_coeff[0][x]);
    }
    
    int S,D;
    int curr_pow;
    for (int x=0;x<m;x++){
        S=D=0;
        curr_pow=1;
        singles.clear(),doubles.clear();
        
        for (auto &it:ones){
            if (it<red[x]) S++;
        }
        for (auto &it:twos){
            if (it<red[x]) D+=2;
        }
        
        for (int x=0;x<=S;x++){
            singles.push_back(nCk(S,x)*curr_pow);
            curr_pow=(curr_pow*2)%MOD;
        }
        for (int x=0;x<=D;x++){
            doubles.push_back(nCk(D,x));
        }
        
        res=mul(singles,doubles);
        
        for (int y=0;y<q;y++){
            if (peri[y]>=red[x] && peri[y]-red[x]<res.size()){
                ans[y]+=res[peri[y]-red[x]];
            }
        }
    }
    
    for (int x=0;x<q;x++) printf("%d\n",ans[x]%MOD);
}