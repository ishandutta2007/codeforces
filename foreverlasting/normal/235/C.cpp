//2018.7.31 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
inline int read(){
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline int _max(res x,res y){
    return x>y?x:y;
}
inline int _min(res x,res y){
    return x<y?x:y;
}
const int maxn=2e6+10;
const int maxc=26;
char s[maxn];
struct SAM {
    int t[maxn][maxc],len[maxn],link[maxn],tot,last;
    int ord[maxn],sum[maxn],tim[maxn],tic;
    bool spe[maxn];
    SAM ():tot(1),last(1),tic(0) {}
    void add(int x) {
        int nw=++tot,i;
        spe[nw]=true;
        len[nw]=len[last]+1;
        for (i=last;i && !t[i][x];i=link[i]) t[i][x]=nw;
        if (i) {
            int p=t[i][x];
            if (len[p]==len[i]+1) link[nw]=p; else {
                int q=++tot;
                len[q]=len[i]+1;
                memcpy(t[q],t[p],sizeof t[p]);
                for (int j=i;j && t[j][x]==p;j=link[j]) t[j][x]=q;
                link[q]=link[p],link[p]=link[nw]=q;
            }
        } else link[nw]=1;
        last=nw;
    }
    void prepare() {
        for (int i=1;i<=tot;++i) ++sum[len[i]];
        for (int i=1;i<=tot;++i) sum[i]+=sum[i-1];
        for (int i=tot;i;--i) ord[sum[len[i]]--]=i;
        memset(sum,0,sizeof sum);
        for (int i=tot;i>1;--i) sum[link[ord[i]]]+=(sum[ord[i]]+=spe[ord[i]]);
        sum[0]=sum[1]=0;
    }
    int run(char s[],int n) {
        int ret=0,now=1,mat=0;
        ++tic;
        for (int i=1;i<(n<<1);++i) {
            int x=s[i]-'a';
            while (now!=1 && !t[now][x]) mat=len[now=link[now]];
            if (t[now][x]) now=t[now][x],++mat;
            while (len[link[now]]>=n) mat=len[now=link[now]];
            if (mat>=n && tim[now]!=tic) tim[now]=tic,ret+=sum[now];
        }
        return ret;
    }
} sam;
int main() {
    scanf("%s",s+1);
    int len=strlen(s+1);
    for (int i=1;i<=len;++i) sam.add(s[i]-'a');
    sam.prepare();
    int m;
    scanf("%d",&m);
    while (m--) {
        scanf("%s",s+1),len=strlen(s+1);
        memcpy(s+len+1,s+1,(sizeof s[0])*len);
        s[len<<1|1]='\0';
        int ans=sam.run(s,len);
        printf("%d\n",ans);
    }
    return 0;
}