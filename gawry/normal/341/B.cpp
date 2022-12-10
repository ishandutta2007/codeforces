#include<cstdio>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0;i<(int)(n);i++)
#define FOREACH(i,t) for (typeof(t.begin())i=t.begin();i!=t.end();i++)
typedef vector<int> vi;
typedef long long int64;

const int MAX=100000;
int n,a[MAX];
main(){
	scanf("%d",&n);
	vi s;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(s.empty()||a[i]>s.back())s.push_back(a[i]);else{
			int pos=lower_bound(s.begin(),s.end(),a[i])-s.begin();
			s[pos]=a[i];
		}
	}
	printf("%d\n",s.size());
}