#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int n;
const int MAXN = 210;
int C[MAXN][MAXN];
class S{
public:
	int cnt , tp;
	S () {}
	S (int _cnt , int _tp) : cnt(_cnt) , tp(_tp) {}
};
S s[MAXN];
void init(){
	for(int i = 0 ; i <= 200 ; ++ i)
		C[i][0] = 1;
	for(int i = 1 ; i <= 200 ; ++ i){
		C[i][0] = C[i][i] = 1;
		for(int j = 1 ; j < i ; ++ j)
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	} 
}
const int INF = 1 << 30;
void get(){
	if(n <= 50){
		for(int j = 1 ; j <= n ; ++ j)
			cout << "a";
		cout << "b ";
		cout << "ab" << endl;
		return ;
	}
	int left = n , last = INF , used = 0 , now = 0;
	string ans = ""; 
	while(left){
		int maxn = 0 , usea = 0 , useb = 0;
		for(int i = 1 ; i <= 50 ; ++ i)
			for(int j = 1 ; j <= min(last , 200 - i - j) ; ++ j)
				if(i * C[j][3] <= left){
					if(i * C[j][3] == maxn)
						useb = max(useb , j);
					else if(i * C[j][3] > maxn){
						maxn = i * C[j][3];
						useb = j;
						usea = i;
					}
				}
		left -= maxn , last = useb;
		s[++ now] = S(usea , 0);
		s[++ now] = S(useb , 1);
	}
	for(int i = 1 ; i <= now ; ++ i)
		if(s[i].tp == 1)
		for(int j = i + 1 ; j <= now ; ++ j)
			if(s[j].tp == 1){
				s[i].cnt -= s[j].cnt;
				break;
			}
	int len = 0;
	for(int i = 1 ; i <= now ; ++ i)
		if(s[i].tp == 0)
			for(int j = 1 ; j <= s[i].cnt ; ++ j){
				len ++;
				cout << "a";
			}
		else
			for(int j = 1 ; j <= s[i].cnt ; ++ j){
				len ++;
				cout << "b";
			}
	cout << " abbb" << endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	init();
	get();
	return 0;
}