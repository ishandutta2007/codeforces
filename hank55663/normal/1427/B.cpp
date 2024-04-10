#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    char c[100005];
    scanf("%s",c);
    vector<int> v;
    int sum=0;
    int ans=0;
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='L')sum++;
        else{
            if(sum)
            v.pb(sum);
            sum=0;
            ans++;
            if(i!=0&&c[i-1]=='W')ans++;
        }
        
    }
    int be=0,en=sum;
    if(v.empty()){
        if(ans){
            printf("%d\n",ans+min(en,k)*2);
        }
        else if(k)
        printf("%d\n",k*2-1);
        else
        printf("0\n");
        return ;
    }
    if(c[0]=='L'){
        be=v[0];
        reverse(v.begin(),v.end());
        v.pop_back();
    }
   //   printf("%d\n",ans);
    sort(v.begin(),v.end());
    int tot=en+be;
    for(auto it:v){
        if(k>=it){
            k-=it;
            ans+=it*2;
            ans++;
        }
        else{
            tot+=it;
        }
    }
    //printf("%d\n",ans);
    ans+=min(k,tot)*2;
    printf("%d\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        //cout<<"Case "<<T++<<":\n";
        solve();
    }
}
/*


*/
/*
1 6 6
2 7 4
3 5 2
4 3 1
5 2 5
6 4 0
7 1 3
*/
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/