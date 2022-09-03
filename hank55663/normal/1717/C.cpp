#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(int T){
    int n;
    scanf("%d",&n);
    int a[200005];
    int b[200005];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    for(int i = 0;i<n;i++)scanf("%d",&b[i]);
    vector<int> v;
    for(int i = 0;i<n;i++){
        if(a[i]>b[i]){
            printf("NO\n");
            return;
        }
        if(a[i]==b[i])v.pb(i);
    }
    if(v.empty()){
        for(int i = 0;i<n;i++){
            if(b[i]-b[(i+1)%n]>1){
                printf("NO\n");
                return;
            }
        }
        printf("YES\n");
    }
    else{
        for(int i = 0;i<v.size();i++){
            int now=v[i];
            vector<int> res;
            do{
                res.pb(b[now]);
                now=(now+n-1)%n;
            }while(now!=v[(i+v.size()-1)%v.size()]);
            for(int j=1;j<res.size();j++){
                if(res[j]>res[j-1]+1){
                    printf("NO\n");
                    return;
                }
            }
        }
        printf("YES\n");
    }
  
}
int main(){
    int t=1;
    scanf("%d",&t);
    for(int T=1;T<=t;T++){
        solve(T);
    }
   // printf("%d\n",s.size());
}

/*
*/