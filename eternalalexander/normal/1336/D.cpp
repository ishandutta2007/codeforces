#include <bits/stdc++.h>
int n,s[105],t[105],a[105],s1,t1,s2,t2,s3,t3,sl,tl,sn,tn;
void q(int i,int &t,int &s){
	std::cout<<"+ "<<i<<std::endl;
	std::cin>>tn>>sn;
	t=tn-tl;s=sn-sl;
	tl=tn;sl=sn;
}int find(int x){for(int i=1;;++i)if(i*(i-1)/2==x)return i;}
int main(){
	std::cin>>n>>tl>>sl;
	for(int i=2;i<n-1;++i)q(i,t[i],s[i]);
	q(n,t1,s1);q(n-1,t2,s2);q(n,t3,s3);
	a[n]=find(t3)-1;a[n-2]=s3-s1-1;a[n-1]=s3/(a[n-2]+1)-1;
	a[n-3]=(s2-(a[n-2]+1)*(a[n]+1))/(a[n-2]+1)-1;
	for(int i=n-4;i>=1;i--)
		a[i]=(s[i+2]-((a[i+1]+1)*a[i+3]+a[i+3]*a[i+4]))/(a[i+1]+1)-1;
	a[1]++;
	std::cout<<"! ";for(int i=1;i<=n;++i)std::cout<<a[i]<<" ";
	return 0;
}