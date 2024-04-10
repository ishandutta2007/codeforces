#include<bits/stdc++.h>

#define re register

using namespace std;

inline int read(){

	re int t=0;re char v=getchar();

	while(v<'0')v=getchar();

	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();

	return t;

}

int n,m,t,a[200002],b[200002],ans,pos[200002],l,r,aa[200002],bb[200002],cnt,s[200002];

queue<int>q[12];

int main(){

	n=read();l=r=100000;++l;

	for(re int i=1;i<=n;++i)s[i]=read();

	for(re int i=n;i;--i){

		if(s[i]==0)continue;

		else if(s[i]==1){

			pos[i]=++r;

			aa[++cnt]=i,bb[cnt]=r;

			q[1].push(i);

		}

		else if(s[i]==2){

			if(q[1].empty())return puts("-1"),0;

			re int xx=q[1].front();

			q[1].pop();

			pos[i]=--l;

			aa[++cnt]=xx,bb[cnt]=pos[i];

			aa[++cnt]=i,bb[cnt]=pos[i];

			q[2].push(i);

		}

		else{

			if(q[2].empty()&&q[1].empty())return puts("-1"),0;

			if(!q[2].empty()){

				re int xx=q[2].front();

				q[2].pop();

				pos[i]=++r;

				aa[++cnt]=xx,bb[cnt]=pos[i];

				aa[++cnt]=i,bb[cnt]=pos[i];

			}

			else{

				re int xx=q[1].front();

				q[1].pop();

				pos[i]=++r;

				aa[++cnt]=xx,bb[cnt]=pos[i];

				aa[++cnt]=i,bb[cnt]=pos[i];

			}

			q[2].push(i);

		}

	}

	printf("%d\n",cnt);

	for(re int i=1;i<=cnt;++i)bb[i]-=l-1,printf("%d %d\n",n-bb[i]+1,aa[i]);

}