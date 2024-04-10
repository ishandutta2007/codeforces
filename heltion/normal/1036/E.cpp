#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL read(){LL x; scanf("%lld", &x); return x;}
void read(char *s){scanf("%s", s);}
void no(){printf("-1"); exit(0);}

#define maxn 1200
#define maxx 240000


LL gcd(LL a, LL b){
	if(a < 0) a = -a;
	if(b < 0) b = -b;
	return b ? gcd(b, a % b) : a;
}

struct point{
	LL x, y;
	
};

bool operator < (const point &A, const point &B){
	return A.x < B.x || A.x == B.x && A.y < B.y;
}
point operator - (const point &A, const point &B){
	return (point){A.x - B.x, A.y - B.y};
}
point operator + (const point &A, const point &B){
	return (point){A.x + B.x, A.y + B.y};
}
point operator * (const point &A, const LL &B){
	return (point){A.x * B, A.y * B};
}
point operator / (const point &A, const LL &B){
	return (point){A.x / B, A.y / B};
}
LL cross(const point &A, const point &B){
	return A.x * B.y - A.y * B.x;
}


struct segment{
	point A, B;
}s[maxn];

map<point, LL> mp;

bool intersection(segment p, segment q, point &o){
	LL U = cross(q.A - p.A, q.B - q.A);
	LL D = cross(p.B - p.A, q.B - q.A);
	if(D == 0) return false;
	if(D < 0){
		D = -D;
		U = -U;
	}
	if(U < 0 || U > D) return false;
	o = (p.B - p.A) * U;
	if(o.x % D || o.y % D) return false;
	o = p.A +  o/ D;
	return true;
}

LL a[maxn];

int main(){
	LL ans = 0;
	int n = read();
	for(int i = 1; i <= n + 1; i += 1){
		a[i] = (i + 1) * i / 2;
	}
	for(int i = 0; i < n; i += 1){
		s[i].A.x = read();
		s[i].A.y = read();
		s[i].B.x = read();
		s[i].B.y = read();
		ans += gcd(s[i].B.y - s[i].A.y, s[i].B.x - s[i].A.x) + 1;
	}
	for(int i = 0; i < n; i += 1)
		for(int j = i + 1; j < n; j += 1){
			point o;
			if(intersection(s[i], s[j], o) && intersection(s[j], s[i], o)){
				mp[o] += 1;
			}
		}
	for(auto p: mp){
		//printf("%lld\n", p.second);
		ans -= lower_bound(a, a + n, p.second) - a;
	}
	printf("%lld", ans);
}