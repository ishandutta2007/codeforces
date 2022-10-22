#include <bits/stdc++.h>

using namespace std;

char s[100005];

int Abs(int x){
	return x>0?x:-x;
}

int Min(int x, int y){
	return x<y?x:y;
}

int main(){

	int n, p;
	scanf("%d%d", &n, &p);
	scanf("%s", s);
	int ans=0;
	int p1=-1, p2;
	for(int i=0; i*2 < n; ++i){
		if(s[i] != s[n-i-1]){
			if(p1 == -1)p1=i;
			p2=i;
		}
	}
	if(p1 == -1){
		puts("0");
		return 0;
	}
	ans=Min(Min(Min(Abs(p-p1-1), Abs(p-p2-1)), Abs(p-(n-p2))), Abs(p-(n-p1)));
	ans += p2-p1;
	for(int i=0; i*2 < n; ++i){
		ans += Min(Min(Abs(s[i]-s[n-1-i]), Abs(s[i]+26-s[n-1-i])), Abs(s[i]-26-s[n-1-i]));
	}
	printf("%d\n", ans);
}