#include<stdio.h>
int n;
int a[100100][3];
int v[100100];
int it[1 << 18];
int itp[1 << 18];
void itre(int loc) {
	if (loc == 0)return;
	itre(loc / 2);
	itp[loc * 2] += itp[loc];
	it[loc * 2] += itp[loc];
	itp[loc * 2 + 1] += itp[loc];
	it[loc * 2 + 1] += itp[loc];
	itp[loc] = 0;
}
void itup(int loc) {
	if (loc == 0)return;
	it[loc] = it[loc * 2];
	if (it[loc] < it[loc * 2 + 1])it[loc] = it[loc * 2 + 1];
	itup(loc / 2);
}
void itadd(int loc, int val) {
	itre(loc / 2);
	itp[loc] += val;
	it[loc] += val;
	itup(loc / 2);
}
void itpush(int loc, int val) {
	loc += 1 << 17;
	int start, end;
	start = 1 << 17;
	end = loc;
	while (start <= end) {
		if (start % 2 == 1) {
			itadd(start, val);
			start++;
		}
		if (end % 2 == 0) {
			itadd(end, val);
			end--;
		}
		start /= 2;
		end /= 2;
	}
}
int itcalc() {
	int loc = 1;
	while (loc < (1 << 17)) {
		int x = loc * 2 + 1;
		itp[loc * 2] += itp[loc];
		it[loc * 2] += itp[loc];
		itp[loc * 2 + 1] += itp[loc];
		it[loc * 2 + 1] += itp[loc];
		itp[loc] = 0;
		if (it[x]>0) {
			loc = x;
		}
		else {
			loc = x - 1;
		}
	}
	return loc - (1 << 17);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i][0], &a[i][1]);
		if (a[i][1] == 1) {
			scanf("%d", &a[i][2]);
			v[a[i][0]] = a[i][2];
		}
	}
	v[0] = -1;
	itpush(0, 10000000);
	for (int i = 0; i < n; i++) {
		if (a[i][1] == 1) {
			itpush(a[i][0], 1);
		}
		else {
			itpush(a[i][0], -1);
		}
		printf("%d\n", v[itcalc()]);
	}
	return 0;
}