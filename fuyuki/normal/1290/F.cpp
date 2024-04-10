#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=5,M=N<<2,S=1<<N,mod=998244353;
int n,m,l,x,X,y,Y,A,B,ans,dx[N],dy[N];
int nx[S],px[S],ny[S],py[S],f[32][M][M][M][M][2][2];
void check(int&x){x-=mod,x+=x>>31&mod;}
int main(){
	scanf("%d%d",&n,&m),(l=1<<n--)--,*******f=1;
	FOR(i,0,n)scanf("%d%d",dx+i,dy+i);
	FOR(i,0,l)FOR(j,0,n)if(i>>j&1)
		(dx[j]>0?nx:px)[i]+=abs(dx[j]),(dy[j]>0?ny:py)[i]+=abs(dy[j]);
	FOR(t,0,30)FOR(i,0,nx[l])FOR(j,0,px[l])FOR(k,0,ny[l])FOR(p,0,py[l])FOR(a,0,1)FOR(b,0,1)
		FOR(s,0,l)if(!(i+nx[s]+j+px[s]&1)&&!(k+ny[s]+p+py[s]&1)){
			A=a+(i+nx[s]&1)>(m>>t&1),B=b+(k+ny[s]&1)>(m>>t&1);
			x=i+nx[s]>>1,X=j+px[s]>>1,y=k+ny[s]>>1,Y=p+py[s]>>1;
			check(f[t+1][x][X][y][Y][A][B]+=f[t][i][j][k][p][a][b]);
		}
	check(ans=f[31][0][0][0][0][0][0]+mod-1),cout<<ans;
	return 0;
}