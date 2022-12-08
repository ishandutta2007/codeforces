#include <iostream>
#include <cstdio>

#include <vector>

using namespace std;

const int MAX_N_LENGTH = 20;

long long N;
int nl;
int narray[MAX_N_LENGTH];
int zc;

int case00() {
	
	int ca;
	bool picked1 = false;
	for(int i = 0;i < nl;i++) {
		
		if(narray[i] == 0) {
			if(!picked1) {
				ca = i;
				picked1 = true;
			} else {
				return ca+i-1;
			}
		}
		
	}
	
	return -1;
	
}

int case25() {
	
	int loc2 = -1;
	int loc5 = -1;
	
	for(int i = 0;i < nl;i++) {
		
		if(loc2 == -1 && narray[i] == 2) {
			loc2 = i;
		}
		if(loc5 == -1 && narray[i] == 5) {
			loc5 = i;
		}
	}
	
	if(loc2 == -1 || loc5 == -1) {
		return -1;
	}
	
	int ca = -1;
	if(zc >= 1) {
		bool pass2 = false, pass5 = false;
	
		for(int i = nl-1;i >= 0;i--) {
		
			if(i == loc2) {
				pass2 = true;
				continue;
			}
			if(i == loc5) {
				pass5 = true;
				continue;
			}
			if(narray[i] != 0) {
				ca = nl - 1 - i;
				break;
			}
		
		}
	
		loc2 -= pass2;
		loc5 -= pass5;
	
		if(ca == -1) {
			return -1;
		}
	} else {
		ca = 0;
	}
	
	if(loc5 > loc2) {
		loc2++;
	}
	
	return ca + (loc5 + loc2 - 1);
	
}

int case50() {
	
	int loc5 = -1, loc0 = -1;
	
	for(int i = 0;i < nl;i++) {
		if(loc0 == -1 && narray[i] == 0) {
			loc0 = i;
		}
		if(loc5 == -1 && narray[i] == 5) {
			loc5 = i;
		}
	}
	if(loc0 == -1 || loc5 == -1) {
		return -1;
	}
	
	int ca = -1;
	
	if(zc >= 2) {
		bool pass0 = false, pass5 = false;
	
		for(int i = nl-1;i >= 0;i--) {
		
			if(i == loc0) {
				pass0 = true;
				continue;
			}
			if(i == loc5) {
				pass5 = true;
				continue;
			}
			if(narray[i] != 0) {
				ca = nl - 1 - i;
				break;
			}
		
		}
	
		loc0 -= pass0;
		loc5 -= pass5;
	
		if(loc0 > loc5) {
			loc5++;
		}
	
		if(ca == -1) {
			return -1;
		}
	} else {
		ca = 0;
	}
	
	if(loc0 > loc5) {
		loc5++;
	}
	
	return ca + (loc0 + loc5 - 1);
	
}

void asans(int &ans, int test) {
	
	if(test != -1 && (ans == -1 || test < ans)) {
		ans = test;
	}
	
}

int main() {
	
	scanf("%I64d", &N);
	
	long long ntemp = N;
	
	nl = 0;
	zc = 0;
	for(int i = 0;ntemp > 0;i++) {
		
		narray[i] = ntemp%10;
		if(narray[i] == 0) {
			zc++;
		}
		
		ntemp = ntemp / 10;
		
		nl++;
	}
	for(int i = 0;i < nl;i++) {
		if(narray[i] == 0 || narray[i] == 2 || narray[i] == 5) {
			
		} else if(narray[i] == 7) {
			narray[i] = 2;
		} else {
			narray[i] = 1;
		}
	}
	
	int ans = -1;
	asans(ans, case00());
	asans(ans, case25());
	asans(ans, case50());
	
	printf("%d\n", ans);
	
}