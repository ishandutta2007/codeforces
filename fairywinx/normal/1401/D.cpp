#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <assert.h>
#include <iomanip>
#include <deque>
#include <map>
#include <random>
// #include <cmath>
#include <bitset>

#include <algorithm>
#define int long long
#define SOLVE int t; cin >> t; while(t--) solve();
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma optimize("O3")

using namespace std;

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	#endif
		srand(time(0));
}

const int N = 1e5 + 228;
const int MOD = 1e9 + 7;

vector<pair<int, int>> G[N];
int kol[N];
int n;

int dfs(int v, int p) {
	int sum = 1;
	for(auto i: G[v]) {
		if (i.first == p)
			continue;
		int z = dfs(i.first, v);
		kol[i.second] = (n - z) * z;
		sum += z;
	}
	return sum;
}

void solve() {
	cin >> n;
	for(int i = 0; i < n; ++i) 
		G[i].clear();
	int id = 0;
	for(int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		G[a - 1].emplace_back(b - 1, id);
		G[b - 1].emplace_back(a - 1, id++);
	}
	dfs(0, -1);
	int m;
	cin >> m;
	vector<int> p(max(m, n - 1), 1);
	for(int i = 0; i < m; ++i)
		cin >> p[i];
	sort(p.begin(), p.end());
	vector<int> d(n - 1, 1);
	for(int i = 0; i < n - 2; ++i)
		d[i] = p[i];
	for(int i = n - 2; i < p.size(); ++i)
		d[n - 2] = (d[n - 2] * p[i]) % MOD;
	int ans = 0;
	vector<int> val(n - 1);
	for(int i = 0; i < n - 1; ++i)
		val[i] = kol[i];
	sort(val.begin(), val.end());
	for(int i = 0; i < n - 1; ++i)
		ans = (val[i] * d[i] + ans) % MOD;
	cout << ans << '\n';
}

signed main() {
	setup();
	SOLVE;

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}

/*
===%@%=====@@@@@%**@##@@%%@%@@@@%%%%@@@@@@@@@@@@@@@@@@@@@%%%%%+*::::::::::::::::::::::::::::::::::::::::::
=====%@@%=%@@@@@%*%###@@@@@@@@@@%%%@@@@@@@@@@@@@@@@@@@@@@@@%======+:::::::::::::::::::::::::::::::::::::::
=======%@@@@@@@@%*@###@@@@@@@@@@%%%%%%@@@@@@@@@@@@@@@@@@@@@%%%==%===*:::::::::::::::::::::::::::::::::::::
#%=======%@@@@@@==####@@@@@@@@%%%%%%%+%%@@@@@@@@@@@@@@@@@@#%%%=%=+=%=+::::::::::::::::::::::::::::::::::::
+:::*======%@@@@=@####@@@@@@@%%+=%=+=%%%%@@@@@@@@@@@@@@@@@@#%%%%=%%==%*:::::::::::::::::::::::::::::::::::
*::::::*=====@@@=#####@@@@@@%%%%=++%%%%%%@@@@@@@@@@@@@@@@@@@#@%%%%=%%%=:::::::::::::::::::::::::::::::::::
=:::::::**======@#####@@@@@@%%%++%=++%%%@@@@@@@@@@@@@@@@@@@@@@##@%%%%%=:::::::::::::::::::::::::::::::::::
%+*::::****+====#######@@@@@%=+=%%%%%%%@#@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%*:::::::::::::::::::::::::::::::::
%=***********+=%#######@@@@@@%%%%%%%%%##@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%**::::::::::::**************:::::
%%+***::::::::*=#######@@@@@@@#@@@@##@@@@@@@@@@@@@@@@@@@@%%%%%%%%%%%%%%%%%==:::::::::::*************::::::
%%@%%+:::::::::%########@@@@@@@@@@@@@%%%%%%%%%%%%%%%%=====+++++++%%%%%%=+++++::::::::::**********:::::::::
+=%%%%%=*:::::*@########@@@@@@@%%%%%%==++++=%%%%%%%=++++++++++++%%%+++=%%=+*+=*:::::::::::::::::::::::::::
+%%@%%%%%=::::+@########@@@%%%%=+++++++++=%%%=+++=%%%%+++++++++%%=++++++=%%=+%=:::::::::::::::::::::::::::
%%%%@@@%%%%*::=##########%%=+++++++++++=%%%=++++++++=%%%=++++=%%=+++++++++%%%%%=*::::::::::::::::::::::::*
@@@@@@@@@%%=::%##########@%%%=+++++++=%%%=+++++++++++++=%%%==%%=+++++++=+++=%%%++*:::::::::::::::::::::::-
@@@@@@@@@@@@+*@#########@%==%%%%%%=+%%%=++=====+++++===%%%%%%%%%%%%%%%%%%%%%%%%%%%=+::::::::::::::::::::--
@@@@@@@@%@@@=*@#####@@#@%%%++++=%%%%%%%%%%%%%%%%%%%%%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+:::::::::::::::::::---
@@@@@@@@@@@#=*@##@%%@#@%%%%%=%%%%%%%%@@@@@@@@@@@@@#########@@@@@@@@@@@@@@@@@@@@@@@@%*:::::::::::::::::----
@@@@@@@@@##@+=##%%%@#@%%%@##@%%@@@@@@@###########@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%+*:::::::::*-----
@@@@@@#####%++##@%@#@%%%@################@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%=+*:*:-----
@#########@++=@####@@@#############@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%=*::
#########%+++=%@##############@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%=++******************************++==%%%@@@
#######@++*++%@##########@@@@@@@@@@@@@@@@@@@@@@@@@@@@%=+******************++++================++++********
###@@=+****+@########@@@@@@@@@@@@@@@@@@@@@@@@@@%=+***********+=%@@######################@@@@@@@@@@@@@@@@@@
=++********+@####@@@@@@@@@@@@@@@@@@@@@@@@@%+**********+=@###############################@@@@@@@@@@@@@@@@@@
****:::::*=@#@@@@@@@@@@@@@@@@@@@@@@@@@=*********++++++@##############@##################@@@@@@@@@@@@@@@@@@
:::::::=@@@@@@@@@@@@@@@@@@@@@@@@@%=*********=@##=+++++@##############+%#################@@@@@@@@@@@@@@@@@@
::::=@@@@@@@@@@@@@@@@@@@@@@@@%=********+%=++@###%=++++%@@###########@++@##@%############@@@@@@@@@@@@@@@@@@
:+@@@@@@@@@@@@@@@@@@@@@@@%+*******+%@###=+++=#@%+++=%==%%###########%=+*%%=:=%%%%%@%@@##@@@@@@@@@@@@@@@%=+
@@@@@@@@@@@@@@@@@@@@@=+******+=@#######%+++++@@++*****+%+@#@@@%%%%%%:---*=+-:%%%%%@%%%%%@@@@@@@@%%=:******
@@@@@@@@@@@@@@@@%=******+=@###########@+++++++@+++****:***%%%%%%%%%*-----+:--+%%%%@%%%%%@@==+*::::*:******
@@@@@@@@@@@@=+*****+=@################=++++++++++*::------+=%%%%%==*::---:---:=%%%@%%%%%%+:::::-::::+*****
@@@@@@@%+*****+%@####################%@#@@@#####@@%%*-----:====*::=@@@@%%@=---+%%%@%%%%%%=:::::::::*+::***
@@%+*****+%@@@######################@*:+:-%@@###=----------**-----+@@@=--*---:%@%%@%%%%%%=:------::**:****
+=++=%@@@@@@@@#########%#######@@%%%=:----=@##@#=..---------------=@@@*.-----=@@%%@@%%%%%=:------::*::****
+=%%@@@@@@@@@##########=##@@@%%%%%%%%:----:%%=%%*-----------------+=%%-.----+@##%%#@%%%%%%*------*:*-:****
+@%===%%+*:=%*:@#####@@*%%%%%%%%%%%%%+------------------------------:::----*@###@@#@%%%%%%*:-----**:-:****
%@========*::::+##@@%%%==%@@%%%%%%%%%%:-----------------------------------:@@###@@##%%%%%%+------**--:****
@%===========+::=%=%%%%@@@@@%@@%%%%%%%+-----------------------------------=@####@###@%%%%%*------**--:****
@%============+::*+=%%@@@@@@@@@@@@%%%%%*---------------------------------:%#########@%%%%%*-----:+:--:****
@%===========%=:::*%@@@@@@@@@@@@@@%%%%%=:--------------------------------*@#########@%%=%=:-----**---:****
@%==========%==:::+@@@@@@@@@@@@@@@@@@%%%*-------------------------------:%@#####+##@%%=:==:----*+*---:****
@%=========%%@=*:*=@@@@@@@#@@@@@@@@@@%@@%*-------------:---------------*@######=:@@@%%:-++----*+=----:****
@%========%%@@=***%@@@@@@@@#@@@@@@@@@@@#@%*------------------:-------*@#######@*-=@@%*--**---*+=*---:::*:*
@@@%====%%@@#@%+*+@@@@@@@@@@#@@@@@@@@@@##@%+*:--------------------:=@#########%--+@%=---*:---:*+:--::--:**
*%@@@===%@@@#@%*:=@@@@@@@@@@@#@@@@@@@@@@#@+%+++*::-------------:*%@#########@%*--+%=----:--::::--........-
-:+@@@@@@@@@#@%**@@@@@@@@@@@@@#@@@@@@@@@##=++***+++**:-------:=%@@@########@%=:::+=:---.-.........----::--
---:%@@@@@@@#@%*%@@@@@@@@@@@@@@#@@#@@@@@@##=++++++++++++++*+%@@@@@@#######@%%--.-*:------.----::---.......
-::::=@@@@@@#@%%@@@@@@@@@@@@@@@@@####@@@@##########@@%%%%%@@@@@@@@######@@%%+::*****:---:::::--...........
:::::*@@@@@@@@%%==%%@@@@@@@@@@@@@@#####@@@############@%###@@@@@@@#####@@%%=*-:*:---:::::::::-----........
--::::%@@@@@%%==************+=%%@@@######@@###########@@##@@@@@@@@@###@@%%%**--..--------.................
------*@@%======@@@@%%=+++*********=@########@++++++==%%%@%@@@@@@%%##@@@%@=**-..............-.............
:-----:%@%======@@@@@@@@@@@@@@@@%%==@@@#######%+++++***:--::=@%%%%%#@@@@@#@**:-.........---...............
*/