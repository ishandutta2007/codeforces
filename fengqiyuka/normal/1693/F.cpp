#include<bits/stdc++.h>
using namespace std;

const int N=2e5+100;
char s[N];int b[N];

int main()
{
	
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		scanf("%s",s+1);
		int Sum=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='0') Sum++;
		if(Sum<n-Sum){
			for(int i=1;i<=n;i++){
				if(s[i]=='1') s[i]='0';
				else s[i]='1';
			}
			for(int i=1;i<=n/2;i++) swap(s[i],s[n+1-i]);
		}
		Sum=0;int Sum2=0;
		for(int i=0;i<=n;i++) b[i]=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0') Sum++,Sum2++;
			else Sum--;
			if(Sum>=0) b[Sum]=std::max(b[Sum],Sum2);
			else b[0]=std::max(b[0],Sum2);
		}
		for(int i=1;i<=n;i++) b[i]=std::max(b[i],b[i-1]);
		
		int Sum3=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1') break;
			Sum3++;
		}
		int Ans=0;
		while(Sum3!=Sum2) Sum3=b[Sum3],Ans++;
		printf("%d\n",Ans);
	}
	
	return 0;
}