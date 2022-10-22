#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+100;
int a[N],f[N],g[N],ID1[6],ID2[6],tmp1[6],tmp2[6];

int main()
{
	
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	f[1]=g[1]=1;
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1]) f[i]=f[i-1]+1,g[i]=1;
		else g[i]=g[i-1]+1,f[i]=1;
	}
	
	for(int i=1;i<=3;i++) ID1[i]=ID2[i]=1;
	
	ll Ans=1;
	for(int i=2;i<=n;i++){
		
		for(int j=1;j<=3;j++) tmp1[j]=tmp2[j]=i;
		
		if(a[i]>a[i-1]){
			int t=i-1-g[i-1]+1,st;
			
			for(int j=1;j<=3;j++) tmp1[j]=ID1[j];
			
			if(a[t]<a[i]) st=ID2[1];
			else if(a[t-1]<a[i]) st=ID2[2];
			else st=ID2[3];
			
			if(a[i-1]<a[i-2]) tmp1[1]=std::min(tmp1[1],st);
			
			t=i-1-f[i-1]+1;
			if(a[t]>a[i]) st=ID1[1];
			else if(a[t-1]>a[i]) st=ID1[2];
			else st=ID1[3];
			
			tmp2[1]=tmp2[2]=st;
		}
		else{
			int t=i-1-f[i-1]+1,st;
			
			for(int j=1;j<=3;j++) tmp2[j]=ID2[j];
			
			if(a[t]>a[i]) st=ID1[1];
			else if(a[t-1]>a[i]) st=ID1[2];
			else st=ID1[3];
			
			if(a[i-1]>a[i-2]) tmp2[1]=std::min(tmp2[1],st);
			
			t=i-1-g[i-1]+1;
			if(a[t]<a[i]) st=ID2[1];
			else if(a[t-1]<a[i]) st=ID2[2];
			else st=ID2[3];
			
			tmp1[1]=tmp1[2]=st;
		}
		
		for(int j=1;j<=3;j++) ID1[j]=tmp1[j],ID2[j]=tmp2[j];
		
		int t=std::min(ID1[1],ID2[1]);
		Ans=Ans+(i-t+1);
	}
	
	printf("%lld\n",Ans);
	
	return 0;
}