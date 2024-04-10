#include<bits/stdc++.h>
using namespace std;
int main() {
	int T,d,k;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&d,&k);
		int L=0;
		while(2ll*L*L*k*k<=1ll*d*d)L++;
		L--;
		if((1ll*L*L+1ll*(L+1)*(L+1))*k*k<=1ll*d*d)puts("Ashish");
		else puts("Utkarsh");
	}
	return 0;
}