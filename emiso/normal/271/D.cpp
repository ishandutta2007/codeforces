#include <bits/stdc++.h>

#define MOD 1000000021LL
#define MOD2 1000000009LL
#define b1 29
#define b2 31

using namespace std;

long long chash[1515][2], mult[1515][2];
int cbad[1515];

pair<long long, long long> subst(int l, int r) {
	if(!l) return make_pair(chash[r][0], chash[r][1]);
	long long a = ((chash[r][0] - (chash[l-1][0] * mult[r-l+1][0])%MOD )%MOD + MOD)%MOD;
	long long b = ((chash[r][1] - (chash[l-1][1] * mult[r-l+1][1])%MOD2 )%MOD2 + MOD2)%MOD2;
	return make_pair(a,b);
}

int main() {
	set <pair<long long, long long> > p;
	string str, bad;
	int k;
	
	cin >> str >> bad >> k;
	
	cbad[0] = (bad[str[0] - 'a'] - '0') ^ 1;
	chash[0][0] = chash[0][1] = str[0] - 'a' + 1;
	mult[0][0] = mult[0][1] = 1;
	
	for(int i=1;i<(int)str.size();i++) {
		mult[i][0] = (mult[i-1][0] * b1)%MOD;
		mult[i][1] = (mult[i-1][1] * b2)%MOD2;
		
		cbad[i] = ((bad[str[i] - 'a'] - '0') ^ 1) + cbad[i-1];
		
		chash[i][0] = ((chash[i-1][0] * b1)%MOD + str[i] - 'a' + 1)%MOD;
		chash[i][1] = ((chash[i-1][1] * b2)%MOD2 + str[i] - 'a' + 1)%MOD2;
	}
	
	for(int i=0;i<(int)str.size();i++) {
		for(int j=i;j<(int)str.size();j++) {
			
			if(i == 0 && cbad[j] <= k) p.insert(subst(i,j));
			else if(i > 0 && cbad[j] - cbad[i-1] <= k) p.insert(subst(i,j));
		}
	}
	
	printf("%d\n",(int)p.size());
	
	return 0;
}