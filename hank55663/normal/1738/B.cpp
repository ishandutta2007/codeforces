
#include<bits/stdc++.h>
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
    int n,k;
    scanf("%d %d",&n,&k);
    int s[100005];
    for(int i = 0;i<k;i++){
        scanf("%d",&s[i]);
    }
    if(k==1){
        printf("Yes\n");
        return;
    }
    vector<int> v;
    LL sum=s[0];
    for(int i = 0;i+1<k;i++)v.pb(s[i+1]-s[i]);
    int ok=1;
   // if(n!=k){
        int fi=sum/(n-k+1);
        if(sum%(n-k+1)!=0){
            if(sum>=0)fi++;

        }
                    if(fi>v[0])ok=0;
    //}
    

    for(int i = 1;i<v.size();i++){
        if(v[i-1]>v[i])ok=0;
    }
    if(ok)printf("Yes\n");
    else printf("No\n");

}
int main(){
    int t=1;
    scanf("%d",&t);
    for(int T=1;T<=t;T++){
       // cerr<<T<<endl;
        solve(T);
    }
   // printf("%d\n",s.size());
}

/*
*/