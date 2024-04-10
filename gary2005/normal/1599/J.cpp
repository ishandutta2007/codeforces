/**
 *    author:  gary
 *    created: 11.10.2021 21:40:17
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=1e3+1;
int n;
int ans[MAXN];
vector<int> a;
SRAND;
int ti;
const int MOD=(1<<22)-1;
struct HASH_TABLE{
	int tp[MOD];
	vector<int> nex;
    vector<bitset<26> > val;
	vector<mp> is;
	HASH_TABLE(){
		fill(tp,tp+MOD,-1);
	}
	void insert(mp p,bitset<26> v){
		int se=(p.FIR<<2)^p.SEC^(p.FIR>>10);
		se&=MOD;
		nex.PB(tp[se]);
		tp[se]=nex.size()-1;
		val.PB(v);
		is.PB(p);
	}
    bool find(mp p){
		int se=(p.FIR<<2)^p.SEC^(p.FIR>>10);
		se&=MOD;
		for(int now=tp[se];now!=-1;now=nex[now]){
			if(is[now]==p) return true;
		}
        return false;
    }
	bitset<26> query(mp p){
		int se=(p.FIR<<2)^p.SEC^(p.FIR>>10);
		se&=MOD;
		for(int now=tp[se];now!=-1;now=nex[now]){
			if(is[now]==p) return val[now];
		}
		return val[0];
	}
}ht;
void noans(){
    vector<int> A,B;
    while(clock()-ti<980){
        bitset<26> Tmp;
        mp P=II(0,0);
        rep(i,min(n,26)){
            if(random(2)){
                Tmp.set(i);
                P.FIR+=a[i];
                P.SEC++;
            }
        }
        if(ht.find(P)){
            if(ht.query(P)!=Tmp){
                bitset<26> AA,BB;
                AA=ht.query(P);
                BB=AA&Tmp;
                AA^=BB;
                Tmp^=BB;
                rep(i,min(n,26)) if(AA[i]) A.PB(a[i]);else if(Tmp[i]) B.PB(a[i]);
                break;
            }
        }
        else{
            ht.insert(P,Tmp);
        }
    }
    if(A.empty()){
    puts("NO");
    exit(0);
    }
    vector<int> Z;
    rep(i,A.size()) Z.PB(A[i]),Z.PB(B[i]);
    ans[1]=0;
    rb(i,1,A.size()+B.size()-1) ans[i+1]=Z[i-1]-ans[i];
    sort(ALL(Z));
    int now=A.size()*2+1;
    // for(auto it:Z){
    //     cout<<it<<endl;
    // }
    for(auto it:a){
        if(binary_search(ALL(Z),it));
        else{
            ans[now]=it-ans[now-1];
            now++;
        }
    }
    cout<<"YES"<<endl;
    rb(i,1,n) printf("%d ",ans[i]);puts("");
    exit(0);
}
int main(){
    scanf("%d",&n);
    ti=clock();
    a.resize(n);
    rep(i,n) scanf("%d",&a[i]);
    sort(ALL(a));
    a.erase(unique(ALL(a)),a.end());
    if(a.size()!=n){
        ans[1]=1;
        rep(i,a.size()){
            ans[i+2]=a[i]-1;
        }
    }
    else{
        int cnt[2]={0,0};
        for(auto it:a) cnt[it&1]++;
        vector<int> A,B;
        if(cnt[0]>=3){
            cnt[0]=0;
            for(auto it:a) if(it%2==0){
                cnt[0]++;
                if(cnt[0]<=3){
                    A.PB(it);
                }
                else {
                    B.PB(it);
                }
            }
            else B.PB(it);
        }
        else{
            if(cnt[0]>=1&&cnt[1]>=2){
                cnt[0]=0;
                cnt[1]=0;
                for(auto it:a){
                    if(it%2==0){
                        cnt[0]++;
                        if(cnt[0]<=1){
                            A.PB(it);
                        }
                        else{
                            B.PB(it);
                        }
                    }
                    else{
                        cnt[1]++;
                        if(cnt[1]<=2){
                            A.PB(it);
                        }
                        else{
                            B.PB(it);
                        }
                    }
                }

            }
            else{
                noans();
            }
        }
        ans[1]=(A[2]-A[1]+A[0])/2;
        ans[2]=A[0]-ans[1];
        ans[3]=A[1]-ans[2];
        rb(i,3,n-1){
            ans[i+1]=B[i-3]-ans[1];
        }
    }
    puts("YES");
    rb(i,1,n) printf("%d ",ans[i]);puts("");
    return 0;
}