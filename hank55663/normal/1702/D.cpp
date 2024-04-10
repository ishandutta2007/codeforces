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
#define double long double
using namespace std;
int ok[200005];
void solve(){  
    char c[200005];
    int sum=0;
    int p;
    vector<int> v[26];
    scanf("%s %d",c,&p);
    for(int i = 0;c[i]!=0;i++){
        sum+=c[i]-'a'+1;
        ok[i]=1;
        v[c[i]-'a'].pb(i);
    }
    for(int i = 25;i>=0;i--){
        for(auto it:v[i]){
            if(sum>p){
                sum-=i+1;
                ok[it]=0;
            }
        }
    }
    for(int i = 0;c[i]!=0;i++){
        if(ok[i])printf("%c",c[i]);
    }
    printf("\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    //printf("\"");
    while(t--){
        // cerr<<t<<endl;
        solve();
     //   cerr<<t<<endl;
    }
    
   // cerr<<cnt<<endl;
}
/*
*/