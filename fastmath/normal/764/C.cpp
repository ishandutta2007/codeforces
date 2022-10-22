#include <iostream>
#include <vector>

using namespace std;

struct edge{
	int u, v;
};


int main(){
	int n, u, v;
	cin >> n;

	vector <edge> e(n - 1);
	edge new_ed;
	for (int i = 0; i < n - 1; i++){
		cin >> new_ed.u >> new_ed.v;
		e[i] = new_ed;
	}

	vector <int> c(n + 1);
	for (int i = 1; i <= n; i++){
		cin >> c[i];
	}

	vector <edge> bad_edge;
	for (int i = 0; i < n - 1; i++){
		if (c[e[i].u] != c[e[i].v]){
			bad_edge.push_back(e[i]);
		}
	}

	bool check1 = false;
	for (int i = 1; i <= n; i++){
		bool check2 = true;
		for (int j = 0; j < bad_edge.size(); j++){
			if ((bad_edge[j].u != i) & (bad_edge[j].v != i)){
				check2 = false;
				break;
			}
		}

		if (check2){
			cout << "YES" << endl << i;
			check1 = true;
			break;
		}
	}

	if (!check1){
		cout << "NO";
	}

	return 0;
}