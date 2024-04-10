#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int a;
		scanf("%d", &a);
		puts(360%(180-a)?"NO":"YES");
	}
}