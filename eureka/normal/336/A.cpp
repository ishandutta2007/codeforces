#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<iostream>

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back

int main(){
	int x, y;
	cin >> x >> y;
	if (x > 0 && y > 0){
		printf("0 %d %d 0\n", x+y, x+y);
	}else if (x < 0 && y < 0){
		printf("%d 0 0 %d\n", x+y, x+y);
	}else if (x < 0 && y > 0){
		printf("%d 0 0 %d\n", x-y, y-x);
	}else {
		printf("0 %d %d 0\n", y-x, x-y);
	}
	return 0;
}