#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    LL d,k;
    scanf("%lld %lld",&d,&k);
    vector<int> v;
    for(LL i= 0;i<=d;i+=k){
        v.pb(((int)(sqrt(d*d-i*i)+1e-8))/k);
    }
 //   for(auto it:v)printf("%d ",it);
  // printf("\n");
    for(int i = 0;i<v.size();i++){
        if(i==v.size()-1||v[i+1]<i+1){
            int a=v[i]-i;
            int b=0;
            for(int j = i+1;j<v.size();j++){
                if(v[j]==v[i])b++;
            }
            if(b%2==1||a%2==1){
                printf("Ashish\n");
            }
            else{
                printf("Utkarsh\n");
            }
            return;
        }
    }
    printf("Utkarsh\n");
}

int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}