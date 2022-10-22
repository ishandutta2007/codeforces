#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int N=3e5+100;
/*char s[N],Ans[N];int b[N];

void solve(int l,int r){
	if(l==r){
		Ans[l]=s[l];b[l]=0;
		return ;
	}
	int mid=(l+r)>>1;
	solve(l,mid);
	solve(mid+1,r);
	int pd=0,Len=(r-l+1)/2;
	for(int i=1;i<=r-mid;i++){
		int t1=l+i-1,t2=mid+i;
		if(Ans[t1]<Ans[t2]) {pd=-1;break;}
		if(Ans[t1]>Ans[t2]) {pd=1;break;}
	}
	if(pd==0){
		for(int i=0;i<Len;i++){
			int t1=(i^b[l])+mid+1,t2=(i^b[mid+1])+l;
			if(s[t2]<s[t1]) {pd=1;break;}
			if(s[t1]<s[t2]) {pd=-1;break;}
		}
	}
	if(pd==-1){
		for(int i=mid+1;i<=r;i++){
			int t=((i-l)^b[l])+l;
			Ans[i]=s[t];
		}
	}
	else if(pd==1){
		b[l]=(b[mid+1]^Len);
		for(int i=l;i<=mid;i++){
			int t=((i-l)^b[mid+1])+l;
			Ans[i]=s[t];
		}
		for(int i=l;i<=mid;i++) swap(Ans[i],Ans[i+mid-l+1]);
	}
}*/

char s[N];int tp[2*N],p[2*N],g[2*N],Cnt[2*N],g2[2*N];

int main()
{
	
	int n;
	scanf("%d",&n);
	int len=(1<<n);
	scanf("%s",s);
	
//	solve(1,len);
	
	for(int i=0;i<len;i++) Cnt[s[i]-'a']++;
	for(int i=1;i<=25;i++) Cnt[i]+=Cnt[i-1];
	for(int i=len-1;i>=0;i--) g[Cnt[s[i]-'a']--]=i;
	int Sum=0;
	for(int i=1;i<=len;i++){
		int t1=g[i-1],t2=g[i];
		if(i==1||s[t1]!=s[t2]) Sum++;
		p[t2]=Sum;
	}
	
	for(int j=1;j<=n;j++){
		int t=(1<<(j-1));
		for(int i=0;i<len;i++) tp[i]=p[i];
		
		for(int i=0;i<len;i++) 
			if(i<(i^t)) swap(p[i],p[i^t]);
		for(int i=1;i<=len;i++) g[i]=(g[i]^t);
		
		for(int i=0;i<=len;i++) Cnt[i]=0;
		for(int i=0;i<len;i++) Cnt[tp[i]]++;
		for(int i=0;i<=len;i++) Cnt[i]+=Cnt[i-1];
		for(int i=len;i>=1;i--){
			int x=g[i];
			g2[Cnt[tp[x]]--]=x;
		}
		for(int i=1;i<=len;i++) g[i]=g2[i];
		Sum=0;
		for(int i=1;i<=len;i++){
			int t1=g[i-1],t2=g[i];
			if(i==1||tp[t1]!=tp[t2]||tp[t1^t]!=tp[t2^t]) Sum++;
			p[t2]=Sum;
		}
	}
	
	int Ans=g[1];
	for(int i=0;i<len;i++) printf("%c",s[(i^Ans)]);
	printf("\n");
	
	return 0;
}