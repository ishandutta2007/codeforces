#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL read(){LL x; scanf("%lld", &x); return x;}
void read(char *s){scanf("%s", s);}
void no(){printf("No"); exit(0);}

#define maxn 120000
#define maxm

multiset<LL, greater<int> > a, b;

int main(){
	LL ans = 0;
	int n = read();
	for(int i = 0; i < n; i += 1) a.insert(read());
	for(int i = 0; i < n; i += 1) b.insert(read());
	for(int i = 0; i < n; i += 1){
		if(a.empty()) b.erase(b.begin());
		else{
			if(b.empty()){
				ans += *a.begin();
				a.erase(a.begin());
			}
			else{
				if(*a.begin() < *b.begin()) b.erase(b.begin());
				else{
					ans += *a.begin();
					a.erase(a.begin());
				}
			}
		}
		
		if(b.empty()) a.erase(a.begin());
		else{
			if(a.empty()){
				ans -= *b.begin();
				b.erase(b.begin());
			}
			else{
				if(*b.begin() < *a.begin()) a.erase(a.begin());
				else{
					ans -= *b.begin();
					b.erase(b.begin());
				}
			}
		}
	}
	printf("%lld\n", ans);
}