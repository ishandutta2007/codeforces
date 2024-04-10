#include <stdio.h>
#define N 100010
#define M 320
bool p[M];
int pset[80],pt,max[N],n,tmp,ans=1,now,tmax,bdr,save;
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
void build(){
	for( int i=2;i<M;i++ ) if( !p[i] ){
		pset[pt++] = i;
		for( int j=i;j*i<M;j++ ) p[i*j] = true;
	}
}
int main(){
	build(); n = getint(); while( n-- ){
		now = getint(); if( now == 1 ) continue;
		tmp = now; tmax = 0;
		for( int i=0;pset[i]<=tmp&&i<pt;i++ ) if( !( tmp%pset[i] ) ){
			while( !(tmp%pset[i]) ) tmp /= pset[i];
			if( max[pset[i]]>tmax ) tmax = max[pset[i]];
		}
		if( tmp>1&&max[tmp]>tmax ) tmax = max[tmp];
		save = tmax+1; if( save>ans ) ans = save; tmp = now;
		for( int i=0;pset[i]<=tmp&&i<pt;i++ ) if( !( tmp%pset[i] ) ){
			while( !(tmp%pset[i]) ) tmp /= pset[i];
			if( save>max[pset[i]] ) max[pset[i]]=save;
		}
		if( tmp>1&&save>max[tmp] ) max[tmp]=save;
	}
	printf("%d\n",ans);
}