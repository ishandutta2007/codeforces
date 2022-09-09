#include<bits/stdc++.h>
using namespace std;
int main(){
	typedef pair<int, int> pii;
	priority_queue<pii, vector<pii>, greater<pii> > IQ;
	priority_queue<pii, vector<pii>, less<pii> > EQ;
	int n;
	scanf("%d", &n);
	int *w = new int [n];
	char *s = new char [2 * n + 1];
	for(int i = 0; i < n; i += 1) scanf("%d", w + i);
	for(int i = 0; i < n; i += 1) IQ.push((pii){w[i], i});
	scanf("%s", s);
	for(int i = 0, u; i < 2 * n; i += 1)
		switch(s[i]){
			case '0':{
				u = IQ.top().second;
				IQ.pop();
				EQ.push((pii){w[u], u});
				printf("%d ", u + 1);
				break;
			}
			case '1':{
				u = EQ.top().second;
				EQ.pop();
				printf("%d ", u + 1);
				break;
			}
		}
}