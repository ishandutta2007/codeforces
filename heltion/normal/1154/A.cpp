#include<bits/stdc++.h>
using namespace std;
using LL = long long;
void no(const char *s = "NO"){cout << s;exit(0);} 
int x[4];
int main(){
	ios::sync_with_stdio(false); 
	for(int i = 0; i < 4; i += 1) cin >> x[i];
	int *p = max_element(x, x + 4);
	for(int i = 0; i < 4; i += 1) if(x + i != p)
		cout << *p - x[i] << " ";
}