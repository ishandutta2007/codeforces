#include <bits/stdc++.h>

using namespace std;

int n, x[2];
int a[100005];

long long getHits(long long t, int ind){
	return t/x[ind];
}

int main(){
	cin >> n >> x[0] >> x[1];
	long long t=0;
	long long totHits=0;
	for(int i=0; i < n; ++i){
		scanf("%d", a+i);
		totHits = a[i];
		long long lo=t, hi=1000000000000000000LL;
		while(hi-lo > 1){
			long long mid=(lo+hi)/2;
			if(getHits(mid, 0)+getHits(mid, 1) >= totHits)
				hi=mid;
			else
				lo=mid;
		}
		bool vanya, vova;
		vova=(getHits(hi, 0) > getHits(lo, 0));
		vanya=(getHits(hi, 1) > getHits(lo, 1));
		if(vova && vanya)
			puts("Both");
		else if(vova)
			puts("Vova");
		else
			puts("Vanya");
	}
}