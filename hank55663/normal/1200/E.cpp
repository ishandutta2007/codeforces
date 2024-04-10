#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 1500005
int f[1000005];
void KMP(char *c){
    int j=-1;
    f[0]=-1;
    for(int i = 1;c[i]!=0;i++){
        while(j!=-1&&c[j+1]!=c[i])j=f[j];
        if(c[j+1]==c[i])j++;
        f[i]=j;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    string ans;
    for(int i = 0;i<n;i++){
        char c[1000005];
        scanf("%s",c);
        int len=strlen(c);
        KMP(c);
        int len2=ans.size();
        int now=-1;
        for(int j=max(0,len2-len-10);j<len2;j++){
            while(now!=-1&&c[now+1]!=ans[j])now=f[now];
            if(c[now+1]==ans[j])now++;
        }
        for(int j = now+1;j<len;j++){
            ans+=c[j];
        }
       // cout<<ans<<endl;
    }
    printf("%s\n",ans.c_str());
}