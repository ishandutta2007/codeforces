#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int mo=1e9+7;
const int inf=1e9;
char a[N];
int main(){
	scanf("%s",a+1);
	int n=strlen(a+1);
	vector<vector<int>>res;
	for(;;){
		int l=1,r=n;
		while(l<=n&&a[l]!='(')++l;
		while(r&&a[r]!=')')--r;
		if(l>r)break;
		vector<int>vl,vr;
		vl.push_back(l);vr.push_back(r);
		a[l]=a[r]=0;
		for(;;){
			while(l<=n&&a[l]!='(')++l;
			while(r&&a[r]!=')')--r;
			if(l>r)break;
			vl.push_back(l);vr.push_back(r);
			a[l]=a[r]=0;
		}
		reverse(vr.begin(),vr.end());
		res.push_back(vl);
		for(auto&i:vr)res.back().push_back(i);
	}
	printf("%d\n",(int)res.size());
	for(auto&v:res){
		printf("%d\n",(int)v.size());
		for(auto&i:v)printf("%d ",i);printf("\n");
	}
}