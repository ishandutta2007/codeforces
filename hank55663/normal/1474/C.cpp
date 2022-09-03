#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int cnt[1000005];
bool solve(){
	int n;
	scanf("%d",&n);
	int a[2005];
	for(int i = 0;i<2*n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	sort(a,a+2*n);
	for(int i = 2*n-2;i>=0;i--){
		cnt[a[i]]--;
		cnt[a[2*n-1]]--;
		int x=a[2*n-1];
		int tot=2;
		int ok=1;
		vector<pii> v;
		v.pb(mp(a[i],a[2*n-1]));
		multiset<int> s;
		for(int j = 0;j<2*n-1;j++){
			if(j!=i)
			s.insert(a[j]);
		}
		while(s.size()){
			int a=*s.rbegin();
			s.erase(s.find(a));
			if(s.find(x-a)==s.end()){
				ok=0;
				break;
			}
			s.erase(s.find(x-a));
			v.pb(mp(a,x-a));
			x=a;
		}
		if(ok){
			printf("YES\n");
			printf("%d\n",a[i]+a[2*n-1]);
			for(auto it:v){
				printf("%d %d\n",it.x,it.y);
			}
			for(int j=0;j<2*n;j++){
				cnt[a[j]]=0;
			}
			return true;
		}
	}
	printf("NO\n");
    return true;
}
int main(){
    int t=1;//00000;
    scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/