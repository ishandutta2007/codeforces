// Problem: G. Mass Change Queries
// Contest: Codeforces - Educational Codeforces Round 35 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/911/G
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//zhouAKngyang AK IOI!
#include<bits/stdc++.h>
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9') ch=getchar();
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int n,bcnt;
char val[403][400003];
int a[202003],id[202003],inv[403][202003],icnt[403];
//ival[id[i]]iidinv[i]
int pre2[403][103],tp1[640],tp2[202003],d[403];
signed main()
{
    n=read(),bcnt=n>>9;
    //return 0;
    for(int i=0; i<n; ++i) a[i]=read(),++pre2[i>>9][a[i]];
    for(int i=1; i<=bcnt; ++i) for(int j=0; j<=103; ++j) pre2[i][j]+=pre2[i-1][j];
    for(int i=0,l,r; i<=bcnt; ++i) 
    {
        l=i<<9,r=(i+1)<<9;
        for(int j=l; j<r; ++j) id[j]=inv[i][a[j]]=inv[i][a[j]]?inv[i][a[j]]:(val[i][++icnt[i]]=a[j],icnt[i]);
    }
    for(int op,l,r,pl,pr,x,y,m=read(); m--;)
    {
        op=1,l=read()-1,pl=l>>9,r=read()-1,pr=r>>9;
        if(op==1)
        {
            x=read(),y=read();
            if(x==y) continue;
            if(pl==pr)
            {
            	if(inv[pl][x])
            	{
	                int cnt=0;
	                (!inv[pl][y])&&(inv[pl][y]=++icnt[pl],val[pl][inv[pl][y]]=y);
	                for(int j=l; j<=r; ++j) (id[j]==inv[pl][x])&&(id[j]=inv[pl][y],++cnt);
	                if(cnt==pre2[pl][x]-(pl==0?0:pre2[pl-1][x])) inv[pl][x]=0;
	                for(int j=pl; j<=bcnt; ++j) pre2[j][x]-=cnt,pre2[j][y]+=cnt;            		
				}
            }
            else
            {
            	if(inv[pl][x])
            	{
	                int R=(pl+1)<<9;
	                (!inv[pl][y])&&(inv[pl][y]=++icnt[pl],val[pl][inv[pl][y]]=y);
	                for(int j=l; j<R; ++j) (id[j]==inv[pl][x])&&(id[j]=inv[pl][y],++d[pl]);
	                if(d[pl]==pre2[pl][x]-(pl==0?0:pre2[pl-1][x])) inv[pl][x]=0;            		
				}
				if(inv[pr][x])
				{
					int L=pr<<9;
					(!inv[pr][y])&&(inv[pr][y]=++icnt[pr],val[pr][inv[pr][y]]=y);
	                for(int j=L; j<=r; ++j) (id[j]==inv[pr][x])&&(id[j]=inv[pr][y],++d[pr]);
	                if(d[pr]==pre2[pr][x]-pre2[pr-1][x]) inv[pr][x]=0;					
				}
                for(int j=pl+1,L,R; j<pr; ++j) if(inv[j][x]) if(inv[j][y])
                {
                    L=j<<9,R=(j+1)<<9;
                    for(int k=L; k<R; ++k) (id[k]==inv[j][x])&&(id[k]=inv[j][y]);
                    val[j][inv[j][x]]=0,inv[j][x]=0,d[j]=pre2[j][x]-pre2[j-1][x];
                }
                else val[j][inv[j][x]]=y,inv[j][y]=inv[j][x],inv[j][x]=0,d[j]=pre2[j][x]-pre2[j-1][x];
                for(int j=pl,cnt=0; j<=bcnt; ++j) cnt+=d[j],d[j]=0,pre2[j][x]-=cnt,pre2[j][y]+=cnt;
            }
        }
    }
    for(int i=0; i<n; ++i) printf("%d ",val[i>>9][id[i]]);
	return 0;
}