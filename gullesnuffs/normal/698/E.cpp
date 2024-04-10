#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int numLeapYears(int to){
	int ret = (to-1)/4-(to-1)/100+(to-1)/400;
	return ret;
}

int numLeapYears(int from, int to){
	return numLeapYears(to)-numLeapYears(from);
}

ll year2Time(ll year){
	return (year*365+numLeapYears(year))*86400;
}

ll month2Time(int month, int year){
	int ret=0;
	if(month > 1)ret += 31;
	if(month > 2){
		if(numLeapYears(year+1)-numLeapYears(year) == 1)
			ret += 29;
		else
			ret += 28;
	}
	if(month > 3)ret += 31;
	if(month > 4)ret += 30;
	if(month > 5)ret += 31;
	if(month > 6)ret += 30;
	if(month > 7)ret += 31;
	if(month > 8)ret += 31;
	if(month > 9)ret += 30;
	if(month > 10)ret += 31;
	if(month > 11)ret += 30;
	if(month > 12)ret += 31;
	return ret*86400;
}

struct Date{
	int s, m, h, D, M, Y;

	Date(){
		s=0;
		m=0;
		h=0;
		D=1;
		M=1;
		Y=1970;
	}

	ll toTime(){
		ll ret=year2Time(Y);
		ret += month2Time(M, Y);
		ret += (D-1)*86400;
		ret += h*3600;
		ret += m*60;
		ret += s;
		return ret;
	}

	int getWeekday(){
		ll t=toTime();
		ll days=t/86400;
		return ((days+6)%7)+1;
	}

	void removeD(){
	}
	
	void removeHour(){
		--h;
		if(h < 0){
			h += 60;
			removeD();
		}
	}
	
	void removeMinute(){
		--m;
		if(m < 0){
			m += 60;
			removeHour();
		}
	}

	void removeSecond(){
		--s;
		if(s < 0){
			s += 60;
			removeMinute();
		}
	}
};

int s, m, h, day, date, month;

bool matches(Date d){
	if(s != -1 && s != d.s)
		return 0;
	if(m != -1 && m != d.m)
		return 0;
	if(h != -1 && h != d.h)
		return 0;
	if(month != -1 && month != d.M)
		return 0;
	bool dayMatches=(date == d.D);
	bool dateMatches=(day == d.getWeekday());
	if(dayMatches || dateMatches || (day == -1 && date == -1))
		return 1;
	return 0;
}

ll solve(ll t){
	Date cur;
	t += cur.toTime();
	cur.Y=t/(366*86400);
	while(cur.toTime()+86400*367 < t)
		++cur.Y;
	if(s == -1)
		cur.s=59;
	else
		cur.s=s;
	if(m == -1)
		cur.m=59;
	else
		cur.m=m;
	if(h == -1)
		cur.h=23;
	else
		cur.h=h;
	while(true){
		ll curT=cur.toTime();
		if(curT > t && matches(cur)){
			cur.s=0;
			cur.m=0;
			cur.h=0;
			while(cur.toTime()+4000 < t)
				++cur.h;
			while(true){
				curT=cur.toTime();
				if(curT > t && matches(cur)){
					return curT;
				}
				++cur.s;
				if(cur.s == 60){
					cur.s=0;
					++cur.m;
				}
				if(cur.m == 60){
					cur.m=0;
					++cur.h;
				}
			}
			assert(0);
		}
		cur.D++;
		Date nextMonth=cur;
		nextMonth.M++;
		nextMonth.D=1;
		if(nextMonth.toTime() == curT+86400){
			cur=nextMonth;
			if(nextMonth.M == 13){
				cur.M=1;
				++cur.Y;
			}
		}
	}
}

int main(){
	Date d;
	/*d.D=19;
	d.M=7;
	d.Y=2016;*/
	int tmp=d.getWeekday();
	ll start=d.toTime();
	scanf("%d%d%d%d%d%d", &s, &m, &h, &day, &date, &month);
	int n;
	scanf("%d", &n);
	while(n--){
		ll t;
		scanf("%I64d", &t);
		printf("%I64d\n", (solve(t)-start));
	}
}