#include<bits/stdc++.h>
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define cpii const pii
#define cpdd const pdd
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define LL long long 
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	set<int> s1,s2;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(s1.find(x)==s1.end()){
			s1.insert(x);
		}
		else if(s2.find(x)==s2.end()){
			s2.insert(x);
		}
		else{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n%d\n",s1.size());
	for(auto it:s1){
		printf("%d ",it);
	}
	printf("\n%d\n",s2.size());
	vector<int> v;
	for(auto it:s2)
	v.pb(it);
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	for(auto it:v)
	printf("%d ",it);
	printf("\n");
}