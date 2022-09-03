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
#define last Last
#define MXN 200005
const int mod=1e9+7;
void solve(){
    map<string,LL> ans;
    map<string,string> pre,suf;
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        char c[1005],op[10];
        scanf("%s %s",c,op);
        string cc(c);
        if(op[0]!=':'){
            char a[1005],op[10],b[1005];
            scanf("%s %s %s",a,op,b);
            string aa(a),bb(b);
            ans[cc]=ans[aa]+ans[bb];
            string str=suf[aa]+pre[bb];
           // cout<<str<<endl;
            for(int i = 0;i+3<str.size();i++){
                if(str[i]=='h'&&str[i+1]=='a'&&str[i+2]=='h'&&str[i+3]=='a')ans[cc]++;
            }
            if(pre[aa].size()>=3&&suf[bb].size()>=3){
                pre[cc]=pre[aa];
                suf[cc]=suf[bb];
            }
            else if(pre[aa].size()>=3&&suf[bb].size()<3){
                str=suf[aa]+suf[bb];
                pre[cc]=pre[aa];
                suf[cc]="";
                int len=str.size();
                 for(int i = max(len-3,0);i<len;i++)suf[cc]+=str[i];
            }
            else if(pre[aa].size()<3&&suf[bb].size()<3){
                str = pre[aa]+suf[bb];
                pre[cc]=suf[cc]="";
                 for(int i = 0;i<3&&str[i]!=0;i++)pre[cc]+=str[i];
                int len=str.size();
                for(int i = max(len-3,0);i<len;i++)suf[cc]+=str[i];
            }
            else{
                 str=pre[aa]+pre[bb];
                 suf[cc]=suf[bb];
                 pre[cc]="";
                for(int i = 0;i<3&&str[i]!=0;i++)pre[cc]+=str[i];
            }
        }
        else{
            char str[1005];
            scanf("%s",str);
            ans[cc]=0;
            pre[cc]=suf[cc]="";
            for(int i = 0;str[i+3]!=0;i++){
                if(str[i]=='h'&&str[i+1]=='a'&&str[i+2]=='h'&&str[i+3]=='a')ans[cc]++;
            }
            for(int i = 0;i<3&&str[i]!=0;i++)pre[cc]+=str[i];
            int len=strlen(str);
            for(int i = max(len-3,0);i<len;i++)suf[cc]+=str[i];
        }
      //  cout<<pre[cc]<<endl;
      //  cout<<suf[cc]<<endl;
       // printf("%d\n",ans[cc]);
        if(i==n){
            printf("%lld\n",ans[cc]);
        }
    }

}
/*
ax+by<=c;
bx+ay<=d;
*/
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--)
        solve();
}
/*
2 3 5 6 1 4
*/