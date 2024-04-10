#include<bits/stdc++.h>
using namespace std;
#define Maxn 1000010
bitset<Maxn> c[1005];
bool calc(int *a,int len,int sum,int *seq1,int &cnt1,int *seq2,int &cnt2){
	c[0][0]=1;
	for(int i=1;i<=len;++i)c[i]=c[i-1]|(c[i-1]<<a[i]);
	if(!c[len][sum/2])return false;
	cnt1=cnt2=0;
	int tmp=sum/2;
	for(int i=len;i>=1;--i)
		if(tmp>=a[i]&&c[i-1][tmp-a[i]]){
			seq1[++cnt1]=a[i];
			tmp-=a[i];
		}else seq2[++cnt2]=a[i];
	return true;
}

int T,n,m;
#define maxn 1005
int h[maxn],v[maxn];
int R[maxn],Rlen,L[maxn],Llen,U[maxn],Ulen,D[maxn],Dlen;

inline void rd(int &x){
	x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
}

int main(){
	rd(T);
	while(T--){
		rd(n);
		int sumh=0,sumv=0;
		for(int i=1;i<=n;++i){
			rd(h[i]);sumh+=h[i];
		}
		rd(m);
		for(int i=1;i<=m;++i){
			rd(v[i]);sumv+=v[i]; 
		}
		if(n!=m||sumh&1||sumv&1){
			puts("No");
			continue;
		}
		if(!calc(h,n,sumh,L,Llen,R,Rlen)){
			puts("No");
			continue;
		}
		if(!calc(v,m,sumv,D,Dlen,U,Ulen)){
			puts("No");
			continue;
		}
		sort(L+1,L+Llen+1);
		sort(R+1,R+Rlen+1);
		sort(U+1,U+Ulen+1);
		sort(D+1,D+Dlen+1);
		puts("Yes");
		if(Rlen<Ulen){
			reverse(R+1,R+Rlen+1);
			reverse(L+1,L+Llen+1);
			int x=0,y=0;
			for(int i=1;i<=Rlen;++i){
				x+=R[i];
				printf("%d %d\n",x,y);
				y+=U[i];
				printf("%d %d\n",x,y);
			}
			for(int i=Rlen+1;i<=Ulen;++i){
				x-=L[i-Rlen];
				printf("%d %d\n",x,y);
				y+=U[i];
				printf("%d %d\n",x,y);
			}
			for(int i=1;i<=Dlen;++i){
				x-=L[i+Ulen-Rlen];
				printf("%d %d\n",x,y);
				y-=D[i];
				printf("%d %d\n",x,y);
			}
		}else{
			reverse(U+1,U+Ulen+1);
			reverse(D+1,D+Dlen+1);
			int x=0,y=0;
			for(int i=1;i<=Ulen;++i){
				y+=U[i];
				printf("%d %d\n",x,y);
				x+=R[i];
				printf("%d %d\n",x,y);
			}
			for(int i=Ulen+1;i<=Rlen;++i){
				y-=D[i-Ulen];
				printf("%d %d\n",x,y);
				x+=R[i];
				printf("%d %d\n",x,y);
			}
			for(int i=1;i<=Llen;++i){
				y-=D[i+Rlen-Ulen];
				printf("%d %d\n",x,y);	
				x-=L[i];
				printf("%d %d\n",x,y);
			}
		}
	}
	return 0;
}