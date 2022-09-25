#include <cstdio>
#include <vector>
using namespace std;
int n;
vector<int> factors[100005]; ///proper factors only
vector<int> pfactors[100005];
long long memo[100005];
const long long MOD=1000000007;
long long qexp(int b,int p){
    if (p==0) return 1;
    else if (p==1) return b;
    long long r=qexp(b,p>>1);
    r=(r*r)%MOD;
    if (p&1) r=(r*b)%MOD;
    return r;
}

int coprime(int i,int j){ ///find all coprime numbers to i<=j    
    int ans=0;
    int number;
    for (int x=0;x<(1<<pfactors[i].size());x++){
        number=1;
        for (int y=1;y<(1<<pfactors[i].size());y<<=1){
            if (x&y) number*=pfactors[i][__builtin_ctz(y)];
        }
        if (__builtin_popcount(x)&1){
            ans-=j/number;
        }
        else{
            ans+=j/number;
        }
    }
    return ans;
}

int main(){
    scanf("%d",&n);
    
    for (int x=2;x<=n;x++){
        if (pfactors[x].empty()) pfactors[x].push_back(x);
        for (int y=x*2;y<=n;y+=x){
            factors[y].push_back(x);
            if (factors[x].empty()) pfactors[y].push_back(x);
        }
    }
    
    for (int x=2;x<=n;x++){        
        for (auto it:factors[x]){
            memo[x]+=memo[it]*coprime(x/it,n/it);
            memo[x]%=MOD;
        }
        
        memo[x]=(memo[x]+n)%MOD;
        
        memo[x]=(memo[x]*qexp(n-coprime(1,n/x),MOD-2))%MOD;
    }
    
    int ans=0;
    int inv=qexp(n,MOD-2);
    
    //for (int x=1;x<=n;x++) printf("%d %d\n",x,memo[x]);
    
    for (int x=1;x<=n;x++){
        memo[x]=(memo[x]+1)%MOD;
        ans+=(memo[x]*inv)%MOD;
        ans%=MOD;
    }
    
    printf("%d\n",ans);
}