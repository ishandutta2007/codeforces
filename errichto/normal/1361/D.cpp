#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
 
using ld = long double;
 
struct P {
	long long x, y;
	void read() {
		scanf("%lld%lld", &x, &y);
	}
	long long operator *(const P& he) const {
		return x * he.y - y * he.x;
	}
	bool is_right() const {
		return make_pair(x, y) > make_pair(0LL, 0LL);
	}
	bool operator <(const P& he) const {
		if(is_right() != he.is_right()) {
			return is_right();
		}
		return *this * he < 0;
	}
	long long norm2() const {
		return x * x + y * y;
	}
	ld norm() const {
		return sqrtl(norm2());
	}
};
 
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	// k = n - k;
	// assert(0 <= k && k <= n - 2);
	vector<P> they;
	for(int i = 0; i < n; ++i) {
		P p;
		p.read();
		if(make_pair(p.x, p.y) != make_pair(0LL, 0LL)) {
			they.push_back(p);
		}
	}
	assert((int) they.size() == n - 1);
	n--;
	sort(they.begin(), they.end());
	vector<vector<P>> groups;
	for(int i = 0; i < (int) they.size(); ++i) {
		if(i == 0 || they[i-1] < they[i]) {
			groups.push_back({they[i]});
		}
		else {
			groups.back().push_back(they[i]);
		}
	}
	for(vector<P>& group : groups) {
		sort(group.begin(), group.end(), [&](const P& a, const P& b) {
			return a.norm2() < b.norm2();
		});
	}
	// debug() << imie(groups.size());
	
	ld no_subarray_answer = 0;
	{
		int G = groups.size();
		vector<ld> answer_inside(G);
		ld answer_everybody = 0;
		int hole = n + 1 - k; // possibly 0
		// debug() << imie(hole);
		// #warning special case with no-one-subarray
		ld S = 0;
		int total_added = 0;
		vector<ld> pref_S(G), suf_S(G);
		for(int g = 0; g < G; ++g) {
			const vector<P>& group = groups[g];
			// int added_here = 0;
			for(int i = (int) group.size() - 1; i >= 0; --i) {
				P p = group[i];
				ld my_dist = p.norm();
				answer_everybody += S + my_dist * total_added; // - my_dist * 2 * added_here;
				// S += my_dist;
				// total_added++;
				// added_here++;
			}
			ld S_here = 0;
			for(int i = 0; i < (int) group.size(); ++i) {
				P p = group[i];
				ld my_dist = p.norm();
				answer_inside[g] += i * my_dist - S_here;
				S_here += my_dist;
			}
			pref_S[g] = suf_S[g] = S_here;
			S += S_here;
			total_added += group.size();
		}
		answer_everybody += S; // for origin point
		vector<ld> pref_inside(G), suf_inside(G);
		for(int i = 0; i < G; ++i) {
			pref_inside[i] = answer_inside[i] + (i ? pref_inside[i-1] : (ld) 0);
			pref_S[i] = pref_S[i] + (i ? pref_S[i-1] : (ld) 0);
		}
		for(int i = G - 1; i >= 0; --i) {
			suf_S[i] = suf_S[i] + (i == G - 1 ? (ld) 0 : suf_S[i+1]);
		}
		// printf("%.12Lf\n", answer_everybody);
		// printf("%.12Lf\n", pref_inside[G-1]);
		
		// answer_everybody += pref_inside[G-1];
		if(k == n + 1) {
			debug() << "easy pizi";
			printf("%.12Lf\n", answer_everybody + pref_inside[G-1]);
			return 0;
		}
		// printf(">> %.12Lf\n", answer_inside[0]);
		// printf("<< %.12Lf\n", no_subarray_answer);
		for(int g = 0; g < G; ++g) {
			const vector<P>& group = groups[g];
		// for(const vector<P>& group : groups) {
			int cnt_others = n + 1 - (int) group.size();
			int c = group.size();
			ld others_S = (g ? pref_S[g-1] : (ld) 0) + (g == G - 1 ? (ld) 0 : suf_S[g+1]);
			// for(P p : group) {
				// others_S -= p.norm();
			// }
			vector<ld> pref(c);
			for(int i = 0; i < c; ++i) {
				pref[i] = group[i].norm() + (i ? pref[i-1] : (ld) 0);
			}
			ld prev_square = 0;
			for(int L = 0; L < c; ++L) {
				int R = L + hole - 1;
				if(R >= c) {
					break;
				}
				if(L == 0) {
					// for(int i = 0; i <= R; ++i) {
						// prev_square += (pref[c-1] - pref[i]) - group[i].norm() * (c - i - 1);
						// for(int j = i + 1; j < c; ++j) {
							// prev_square += group[j].norm() - group[i].norm();
						// }
					// }
					// #warning speedup
					int cnt_already = 0;
					ld S_already = 0;
					for(int i = R + 1; i < c; ++i) {
						ld my_dist = group[i].norm();
						prev_square += my_dist * cnt_already - S_already;
						S_already += my_dist;
						cnt_already++;
					}
					// for(int i = 0; i < c; ++i) {
						// for(int j = i + 1; j < c; ++j) {
							// if((!(L <= i && i <= R)) && !(L <= j && j <= R)) {
								// prev_square += abs(group[i].norm() - group[j].norm());
							// }
						// }
					// }
				}
				else {
					int add = L - 1, rem = R;
					prev_square += (group[add].norm() - group[rem].norm()) * (add - (c - rem - 1));
					
					// #warning speedup
					// int rem = L - 1;
					// prev_square += 
					// for(int i = 0; i < rem; ++i) {
						// prev_square -= group[rem].norm() - group[i].norm();
					// }
					// for(int i = R + 1; i < c; ++i) {
						// prev_square -= group[i].norm() - group[rem].norm();
					// }
					// int add = R;
					// prev_square -= (group[rem].norm() - group[add].norm()) * rem;
					// prev_square += (group[rem].norm() - group[add].norm()) * (c - R - 1);
					// for(int i = 0; i < rem; ++i) {
						// prev_square += group[add].norm() - group[i].norm();
					// }
					// for(int i = R + 1; i < c; ++i) {
						// prev_square += group[i].norm() - group[add].norm();
					// }
				}
				ld subtract = -prev_square;
				// #warning speedup
				// for(int i = L; i <= R; ++i) {
					// subtract += group[i].norm() * cnt_others + others_S;
				// }
				// printf("> %.12Lf\n", answer_everybody);
				// printf("> %.12Lf\n", subtract);;
				// printf("1 %.12Lf\n", subtract);
				subtract += (pref[R] - (L ? pref[L-1] : (ld) 0)) * cnt_others + others_S * hole;
				// printf(": %d %.12Lf\n", cnt_others, others_S);
				// printf("> %12Lf\n", (pref[R] - (L ? pref[L-1] : (ld) 0)));
				// printf("2 %.12Lf\n", subtract);
				// printf("> %.12Lf\n", (g ? pref_inside[g-1] : (ld) 0) + (g==G-1 ? (ld) 0 : suf_inside[g+1]));
				// printf("! %.12Lf\n", answer_everybody - subtract);
				debug() << imie(answer_everybody) imie(subtract);
				no_subarray_answer = max(no_subarray_answer, answer_everybody - subtract + (g ? pref_inside[g-1] : (ld) 0) + (g==G-1 ? (ld) 0 : suf_inside[g+1]));
				// printf("> %.12Lf\n", no_subarray_answer);
				// printf("\n");
				
			}
		}
	}
		
	// #warning special case with one line only
	ld answer = 0;
	ld S = 0;
	// S + my_dist * added - my_dist * 2 * added_in_my_group
	int G = groups.size();
	vector<int> added(G);
	int total_added = 0;
	// #warning doesnt work if initially k = n
	// #warning add convex hull
	// vector<
	set<pair<ld, int>> secik;
	for(int g = 0; g < G; ++g) {
		ld my_dist = groups[g].back().norm();
		ld maybe = my_dist * (k - 1) - my_dist * 2 * added[g];
		secik.insert({maybe, g});
	}
	for(int rep = 0; rep < k; ++rep) {
		auto it = secik.end();
		--it;
		pair<ld, int> best = *it;
		int g = best.second;
		secik.erase(it);
		best.first += S;
		/*
		for(int g = 0; g < G; ++g) {
			if(!groups[g].empty()) {
				ld my_dist = groups[g].back().norm();
				ld maybe = S + my_dist * (k - 1) - my_dist * 2 * added[g];
				//                a    *      x      +     b
				//             my_dist * (total_added - 2 * added[g])
				// if(total_added == 0) maybe += my_dist;
				best = max(best, {maybe, g});
			}
		}*/
		// if(total_added == 0) {
			// best.first = 0;
		// }
		// int g = best.second;
		answer += best.first - groups[g].back().norm() * (k - 1 - total_added);
		assert(g != -1);
		S += groups[g].back().norm();
		total_added++;
		added[g]++;
		auto x = groups[g].back().x;
		auto y = groups[g].back().y;
		groups[g].pop_back();
		debug() << imie(S) imie(x) imie(y) imie(g) imie(added[g]);
		
		if(!groups[g].empty()) {
			ld my_dist = groups[g].back().norm();
			ld maybe = my_dist * (k - 1) - my_dist * 2 * added[g];
			secik.insert({maybe, g});
		}
	}
	printf("%.12Lf\n", max(answer, no_subarray_answer));
}