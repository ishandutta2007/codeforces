#include<bits/stdc++.h>
using namespace std;
int n,q,t0[200005],t1[200005],f[200005][20],lg2[200005]={-1};
int s[200005],sxor[200005];
struct Q{
	int op,x,y,z;
}b[200005];
int Getmx(int l,int r){
	int k=lg2[r-l+1];
	return max(f[l][k],f[r-(1<<k)+1][k]);
}
int main(){
	scanf("%d%d",&n,&q);
	set<int> st;
	for(int i=1;i<=n;i++)st.insert(i),lg2[i]=lg2[i>>1]+1;
	for(int i=1,op,x,y,z;i<=q;i++){
		scanf("%d",&op);
		if(op==0){
			scanf("%d%d%d",&x,&y,&z);
			if(!z){
				while(1){
					auto it=st.lower_bound(x);
					if(it==st.end()||(*it)>y)break;
					t0[*it]=i;
					st.erase(it);
				}
			}
			b[i]={op,x,y,z};
		}
		else {
			scanf("%d",&x);
			b[i]={op,x,0,0};
		}
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+(!t0[i]);
		if(!t0[i])sxor[i]=(sxor[i-1]^i);
		else sxor[i]=sxor[i-1];
		f[i][0]=t0[i];
		t1[i]=1e9;
	}
	for(int j=1;j<=17;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
		}
	}
	for(int i=1;i<=q;i++){
		if(b[i].op==0&&b[i].z==1){
			int l=b[i].x,r=b[i].y;
			if(s[r]-s[l-1]!=1)continue;
			int w=sxor[r]^sxor[l-1];
			t1[w]=min(t1[w],max(i,Getmx(l,r)));
		}
	}
	for(int i=1;i<=q;i++){
		if(b[i].op==1){
			if(t0[b[i].x]){
				if(t0[b[i].x]>i)puts("N/A");
				else puts("NO");
				continue;
			}
			if(t1[b[i].x]!=1e9){
				if(t1[b[i].x]>i)puts("N/A");
				else puts("YES");
				continue;
			}
			puts("N/A");
		}
	}
}