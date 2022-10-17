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
     
    struct Item {
    	string name;
    	int type;
    	int base;
    	int size;
    	vector<string> monsters;
    	void print() {
    		cout << name << " " << monsters.size();
    		for(string s : monsters) {
    			cout << " " << s;
    		}
    		cout << endl;
    	}
    	void read() {
    		string s;
    		cin >> name >> s;
    		int a, b, c;
    		cin >> a >> b >> c;
    		cin >> size;
    		if(s == "weapon") {
    			type = 0;
    			base = a;
    		}
    		else if(s == "armor") {
    			type = 1;
    			base = b;
    		}
    		else if(s == "orb") {
    			type = 2;
    			base = c;
    		}
    		else {
    			assert(false);
    		}
    	}
    };
     
    struct Monster {
    	string name;
    	int type;
    	int bonus;
    	string home;
    	void read() {
    		string s;
    		cin >> name >> s >> bonus >> home;
    		if(s[0] == 'g') {
    			type = 0;
    		}
    		else if(s[0] == 's') {
    			type = 1;
    		}
    		else if(s[0] == 'p') {
    			type = 2;
    		}
    		else {
    			assert(false);
    		}
    	}
    };
     
    int main() {
    	int n;
    	cin >> n;
    	vector<Item> items(n);
    	for(Item& item : items) {
    		item.read();
    	}
    	int k;
    	cin >> k;
    	vector<Monster> monsters(k);
    	for(Monster& monster : monsters) {
    		monster.read();
    	}
    	int places = 0;
    	for(Item item : items) {
    		places += item.size;
    	}
    	bool special = false;
    	if(places == k) {
    		// vector<int> answer(3);
    		// for(Item item : items) {
    			// int maybe = item.base;
    			// for(Monster m : monsters) {
    				// if(m.home == item.name && m.type == item.type) {
    					// maybe += m.bonus;
    				// }
    			// }
    			// int x = item.type;
    			// answer[x] = max(answer[x], maybe);
    		// }
    		// debug() << imie(answer);
    		special = true;
    	}
    	set<string> taken;
    	vector<Item> answer(3);
    	for(int type = 0; type < 3; ++type) {
    		vector<pair<int,string>> they;
    		for(Monster monster : monsters) {
    			if(monster.type == type) {
    				they.emplace_back(monster.bonus, monster.name);
    			}
    		}
    		sort(they.rbegin(), they.rend());
    		Item best = items[0];
    		for(Item item : items) {
    			if(item.type == type) {
    				if(!special) {
    					for(int i = 0; i < min(item.size, (int) they.size()); ++i) {
    						item.monsters.push_back(they[i].second);
    						item.base += they[i].first;
    					}
    				}
    				else {
    					for(Monster monster : monsters) {
    						if(monster.home == item.name) {
    							item.monsters.push_back(monster.name);
    							if(monster.type == item.type) {
    								item.base += monster.bonus;
    							}
    						}
    					}
    				}
    				if(best.type != type || item.base > best.base) {
    					best = item;
    				}
    			}
    		}
    		answer[type] = best;
    		for(string s : best.monsters) {
    			taken.insert(s);
    		}
    	}
    	for(Item item : answer) {
    		for(Monster m : monsters) {
    			if((int) item.monsters.size() < item.size 
    				&& !taken.count(m.name)) {
    				taken.insert(m.name);
    				item.monsters.push_back(m.name);
    			}
    		}
    		item.print();
    	}
    }