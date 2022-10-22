#include <bits/stdc++.h>
using namespace std;

struct Node{
	int h, m;
	int noon;
	Node(){}
	Node(int _h, int _m, int _noon){h = _h, m = _m, noon = _noon;}
	bool operator == (const Node &A) const{
		return h == A.h && m == A.m && noon == A.noon;
	}
	bool operator < (const Node &A) const{
		if (noon != A.noon) return noon > A.noon;
		if (h != A.h) return h < A.h;
		return m < A.m;
	}
};

string s;

int main(){
	int n;
	scanf("%d", &n);
	int ans = 1, cnt = 0;
	bool pd = 1;
	Node last = Node(-1, -1, 1);
	getline(cin, s);
	while (n--){
		Node now;
		char c1, c2;
		scanf("[%d:%d %c.%c.]", &now.h, &now.m, &c1, &c2);
		getline(cin, s);
		now.noon = c1 == 'a';
		if (now.h == 12) now.h = 0;
		if (now < last) pd = 0, ans++, cnt = 1;
		else if (now == last){
			cnt++;
			if (cnt == 11) cnt = 1, ans++;
		}
		else cnt = 1, pd = 0;
		last = now;
	}
	printf("%d\n", ans);
	return 0;
}