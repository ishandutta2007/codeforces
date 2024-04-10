#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define forg(i,x) for(int i=first[x];i;i=nxt[i])
#define uu unsigned
#define fi first
#define se second
#define od(x) ((x)&1)
#define ev(x) (od(x)^1)
#define mi2(x) (1<<(x))
#define scanf a1234=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
int a1234;
char buf[1<<18],*bufs=buf,*buft=buf;
inline int gc(){
    return bufs==buft&&(buft=(bufs=buf)+fread(buf,1,1<<18,stdin)),bufs==buft?-1:*bufs++;
}
inline void xxx(){for(;;);}
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=4e5+10;
int n,m,k,nn;
int dr[mxn][2],fd,sx,sy;
const int dx[]={-1,-1,1,1},dy[]={-1,1,-1,1};
char ss[66];
vector<int>v[mxn];
typedef vector<int>::iterator vie;
map<pii,int>mp,bl; 
inline int id(int o,int x,int y){return o?x+y+m+n+5:x-y+m+1;}
int he[mxn];
struct thr{
    int a,b,c;thr(){}
    thr(int aa,int bb,int cc){a=aa,b=bb,c=cc;}
};
thr db[mxn];
bool tmp[mxn];

long long ans=0;

inline void eee(int x,int y){
    bl[pii(x,y)]=1;
    int aa=id(0,x,y),bb=id(1,x,y);
    v[aa].push_back(x),v[bb].push_back(x);
    if(!he[aa])he[aa]=aa-m-1;
    if(!he[bb])he[bb]=bb-m-n-5;
}
inline bool isdu(int x,int y){return bl.find(pii(x,y))!=bl.end();}
    
int main(){
    scanf("%d%d%d",&n,&m,&k);for(int i=1,x,y;i<=k;++i)scanf("%d%d",&x,&y),dr[i][0]=x,dr[i][1]=y,eee(x,y);
    for(int i=0;i<=n+1;++i)eee(i,0),eee(i,m+1); for(int i=1;i<=m;++i)eee(0,i),eee(n+1,i);
    nn=id(1,n+1,m+1);
    for(int i=0;i<=nn;++i)sort(v[i].begin(),v[i].end());
    scanf("%d%d%s",&sx,&sy,ss);
    if(ss[0]=='N')fd=ss[1]=='W'?0:1;
    if(ss[0]=='S')fd=ss[1]=='W'?2:3;
    
    int x=sx,y=sy,o=fd,xh,bu=0,oo;
    
    while(1){
        ++bu;
        //printf("%d %d %d %lld\n",x,y,o,ans);
        if(o==0||o==3)oo=0,xh=id(0,x,y);else oo=1,xh=id(1,x,y);
        vie p=lower_bound(v[xh].begin(),v[xh].end(),x);
        int p1=*(p-1),p2=*p,len=p2-p1-1;
        
        if(bu==1){
            if(o==0||o==1)ans=x-p1,x=p1+1,y=oo?he[xh]-x:x-he[xh];
            else ans=p2-x,x=p2-1,y=oo?he[xh]-x:x-he[xh];
            mp[pii(xh,p1)]=ans;
        }else{
            int &bs=mp[pii(xh,p1)];
            if(bs>len)break;
            if(o==0||o==1)x=p1+1,y=oo?he[xh]-x:x-he[xh];
            else x=p2-1,y=oo?he[xh]-x:x-he[xh];
            ans+=len-bs,bs+=len;
        }
        int o1,o2,x1,x2,y1,y2;
        if(o==0){
            o1=1,x1=x-1,y1=y,o2=2,x2=x,y2=y-1;
        }else if(o==1){
            o1=0,o2=3,x1=x-1,y1=y,x2=x,y2=y+1;
        }else if(o==2){
            o1=0,o2=3,x1=x,y1=y-1,x2=x+1,y2=y;
        }else{
            o1=1,o2=2,x1=x,y1=y+1,x2=x+1,y2=y;
        }
        if(isdu(x1,y1)^isdu(x2,y2)){
            if(isdu(x1,y1))o=o2,x=x2,y=y2;
            else o=o1,x=x1,y=y1;
        }else o=3-o;
        
    }
    printf("%lld\n",ans);
    return 0;
}







namespace task1{
    const int mxn=1003;
    int du[mxn][mxn],vis[mxn][mxn],ans=1;
    int x,y,o;bool fl;
    inline void work(){
        while(1){
            //printf("%d %d %d\n",x,y,o);
            int xx=x+dx[o],yy=y+dy[o];
            if(!du[xx][yy]){
                if(vis[xx][yy])break;vis[x=xx][y=yy]=1,++ans;continue;
            }
            int o1=5,o2=5,x1,x2,y1,y2;
            if(o==0)o1=1,o2=2,x1=x-1,y1=y,x2=x,y2=y-1;
            else if(o==1)o1=0,o2=3,x1=x-1,y1=y,x2=x,y2=y+1;
            else if(o==2)o1=0,o2=3,x1=x,y1=y-1,x2=x+1,y2=y;
            else o1=1,o2=2,x1=x,y1=y+1,x2=x+1,y2=y;
            if(du[x1][y1]==du[x2][y2]){fl=1;break;}
            if(!du[x1][y1]){
                o=o1;if(vis[x1][y1])break;vis[x=x1][y=y1]=1,++ans;
            }else{
                o=o2;if(vis[x2][y2])break;vis[x=x2][y=y2]=1,++ans;
            }
            /*******************************************/
        }
    }

    int main1(){
        for(int i=1;i<=k;++i)du[dr[i][0]][dr[i][1]]=1;
        for(int i=0;i<=n+1;++i)du[i][0]=du[i][m+1]=1;
        for(int i=0;i<=m+1;++i)du[0][i]=du[n+1][i]=1;
        x=sx,y=sy,o=fd;vis[sx][sy]=1;fl=0;
        work();
        if(!fl)return printf("%d\n",ans),0;
        //puts("---------------------__");
        o=3-fd,x=sx,y=sy;
        work();
        printf("%d\n",ans);
        return 0;
    }
}