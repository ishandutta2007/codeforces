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
void solve(){
    char c[200005];
    scanf("%s",c+1);
    int sum[200005];
    sum[0]=0;
    int ok=1;
    int b=0;
    vector<int> v;
    for(int i = 1;c[i]!=0;i++){
        if(c[i]=='?')ok=0,b++,v.pb(i);
        if(c[i]=='?'||c[i]=='(')sum[i]=(sum[i-1]+1);
        else sum[i]=(sum[i-1]-1);
        if(sum[i]<0){
            printf("NO\n");
            return;
        }
    }
    int n=strlen(c+1);
    if(ok){
        if(sum[n]==0)
        printf("YES\n");
        else printf("NO\n");
    }
    else{
        int n=strlen(c+1);
        if(n%2==1){
            printf("NO\n");
            return;
        }
        int a=sum[n];
        b-=a/2;
        int ok=1,st=0;
        a/=2;
        if(a==0||b==0){
            printf("YES\n");
            return;
        }
              //printf("%s\n",c+1);
        for(int i = 0;i<b;i++)c[v[i]]='(';
        for(int i = b;i<v.size();i++)c[v[i]]=')';
          //printf("%s\n",c+1);
        swap(c[v[b]],c[v[b-1]]);
        int sum=0;
        //printf("%s\n",c+1);
        for(int i = 1;c[i]!=0;i++){
            if(c[i]=='(')sum++;
            else sum--;
          //  printf("%d ",sum);
            if(sum<0){
                printf("YES\n");
                return;
            }
        }
        /*if(!ok)printf("YES\n");
        else */printf("NO\n");
    }
}
int main(){
    int t=1;000;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    
}
/*
*/