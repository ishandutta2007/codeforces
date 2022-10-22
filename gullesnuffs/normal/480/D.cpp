#include <bits/stdc++.h>

using namespace std;

int n, S;

struct Parcel{
	int in, out, w, s, v;

	bool operator<(const Parcel &other) const{
		if(out != other.out)
			return out < other.out;
		return in > other.in;
	}
}parcel[505];

int dp[1005];
int val[505][1005];

int main(){
	scanf("%d%d", &n, &S);
	for(int i=0; i < n; ++i)
		scanf("%d%d%d%d%d", &parcel[i].in, &parcel[i].out, &parcel[i].w, &parcel[i].s, &parcel[i].v); 
	parcel[n].in=0;
	parcel[n].out=2*n;
	parcel[n].w=0;
	parcel[n].s=S;
	parcel[n].v=0;
	sort(parcel, parcel+n+1);
	for(int i=0; i <= n; ++i){
		for(int w=0; w <= 1000-parcel[i].w && w <= parcel[i].s; ++w){
			memset(dp, 0, 4008);
			for(int j=0; j < i; ++j){
				if(j && parcel[j].out > parcel[j-1].out){
					for(int k=parcel[j-1].out; k < parcel[j].out; ++k)
						if(dp[k] > dp[k+1])
							dp[k+1]=dp[k];
				}
				if(parcel[j].in < parcel[i].in)
					continue;
				int newval=val[j][w]+dp[parcel[j].in];
				if(newval > dp[parcel[j].out])
					dp[parcel[j].out]=newval;
			}
			if(i)
				val[i][w+parcel[i].w]=dp[parcel[i-1].out];
			else
				val[i][w+parcel[i].w]=0;
			val[i][w+parcel[i].w] += parcel[i].v;
		}
		for(int w=parcel[i].s+parcel[i].w; w <= 1000; ++w)
			val[i][w+1]=val[i][w];
	}
	printf("%d\n", val[n][S]);
}