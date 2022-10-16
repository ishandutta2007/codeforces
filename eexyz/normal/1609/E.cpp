#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
#define py cout<<"YES\n"
#define pn cout<<"NO\n"
#define ll long long
int n,d,q,y,z,i,j,x,qwq,ans;
struct tt{
	int t[6]; 
}t[N<<2],res; 
char s[N],ch;
/*
0 a
1 b
2 c
3 ab
4 bc
5 abc
*/
tt up(tt L,tt R){
	int x;
	memset(res.t,0,sizeof(res.t));
	res.t[5]=L.t[5]+R.t[5];
	x=min(L.t[0],R.t[4]);
	res.t[5]+=x;
	L.t[0]-=x;
	R.t[4]-=x;
	x=min(L.t[3],R.t[2]);
	res.t[5]+=x;
	L.t[3]-=x;
	R.t[2]-=x;
	x=min(L.t[3],R.t[4]);
	res.t[5]+=x;
	L.t[3]-=x;
	R.t[4]-=x;
	L.t[1]+=x;
	x=min(L.t[0],R.t[1]);
	res.t[3]+=x;
	L.t[0]-=x;
	R.t[1]-=x;
	x=min(L.t[1],R.t[2]);
	res.t[4]+=x;
	L.t[1]-=x;
	R.t[2]-=x;
	res.t[0]=L.t[0]+R.t[0];
	res.t[1]=L.t[1]+R.t[1];
	res.t[2]=L.t[2]+R.t[2];
	res.t[3]+=L.t[3]+R.t[3];
	res.t[4]+=L.t[4]+R.t[4];
	return res;
}
void modify(int k,int l,int r,int x,char y){
	if(l==r){
		memset(t[k].t,0,sizeof(t[k].t));
		t[k].t[y-'a']=1;return ;
	}
	if(x<=mid)modify(ls,l,mid,x,y);
	else modify(rs,mid+1,r,x,y);
	t[k]=up(t[ls],t[rs]);
}
void build(int k,int l,int r){
	if(l==r){
		t[k].t[s[l]-'a']=1;
		return ;
	}
	build(ls,l,mid);build(rs,mid+1,r);t[k]=up(t[ls],t[rs]);
//	if(k==1)for(int i=0;i<6;++i)cout<<t[k].t[i]<<" ";
}
int main(){
	cin>>n>>q;
	scanf("%s",s+1);
	build(1,1,n);
	while(q--){
		cin>>x>>ch;s[x]=ch;
		modify(1,1,n,x,ch);
		cout<<t[1].t[5]<<"\n";
	}
}