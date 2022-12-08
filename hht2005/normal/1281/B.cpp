#include<bits/stdc++.h>
using namespace std;
string a,b;
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		cin>>a>>b;
		int n=a.size();
		int i,mi=-1,las=-1,lmi=-1;
		for(i=n-1;i>=0;i--) {
			if(~mi&&a[mi]<a[i])las=i,lmi=mi;
			else if(!~mi||a[i]<a[mi])mi=i;
		}
		if(~las)swap(a[las],a[lmi]);
		if(a<b)cout<<a<<endl;
		else puts("---");
	}
	return 0;
}//UKE