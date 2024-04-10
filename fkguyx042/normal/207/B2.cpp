#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>

#define N 500005
#define K 19

using namespace std;
long long ans;

int F[N][K+1],i,j,m,n,p,k,a[N],nn,G[N],Log[N];

int ST[K+1][N];

void get_ST()
{
     for (i=1;i<=nn;++i) ST[0][i]=i;
     for (i=1;i<=K;++i)
       for (j=1;j+(1<<i)-1<=nn;++j) 
          if (G[ST[i-1][j]]<G[ST[i-1][j+(1<<(i-1))]])
            ST[i][j]=ST[i-1][j];
            else ST[i][j]=ST[i-1][j+(1<<(i-1))];
}

int Find(int x,int y)
{
    int e=Log[y-x+1];
    if (G[ST[e][x]]<G[ST[e][y-(1<<e)+1]]) return ST[e][x];
    return ST[e][y-(1<<e)+1];
}

int main()
{
	 scanf("%d",&n);
	 for (i=1;i<=n;++i) scanf("%d",&a[i]),a[i+n]=a[i];
	 nn=n*2;
	 for (i=1;i<=nn;++i) G[i]=i-a[i];
	 for (i=0,j=1;j<=nn;j<<=1,++i) Log[j]=i;
	 for (i=1;i<=nn;++i) if (!Log[i]) Log[i]=Log[i-1];
	 get_ST();
	 for (i=1;i<=nn;++i)
	 {
	  		if (i-a[i]<=0) continue;
		    int now=Find(i-a[i],i);
		    F[i][0]=now;
		    for (j=1;j<=K;++j)
				F[i][j]=F[F[i][j-1]][j-1];	
	 }
	 for (i=n+1;i<=nn;++i)
	 {
	 	   ++ans;
	       if (i-a[i]<=i-n+1) continue;
	       int cangood=1e9,ist=0,id=i;
	       for (j=K;j>=0;--j) if (G[F[id][j]]<=i-n+1) cangood=ist+(1<<j);
	       else ist+=(1<<j),id=F[id][j];
	       ans+=cangood;
	 }
	 cout<<ans<<endl;
}