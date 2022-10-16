/*input

5
1 0
11 1
111 0
1111 1
11111 0
*/
#include <bits/stdc++.h>

using namespace std;

bool isnumber(const string &a) {
	bool pirm = true;

	if (a == "0")
		return true;

	for (int i = 0; i < a.size(); i++) {
		if (pirm and a[i] == '0')
			return false;
		else
			pirm = false;

		if (!isdigit(a[i]))
			return false;
	}

	return true;
}

int main () {
	int n;
	cin >> n;
	string ss[n];
	bool kur[n];
	int kie[2] = {};

	for (int i = 0; i < n; i++) {
		cin >> ss[i] >> kur[i];
		//cout << ss[i] << " " << isnumber(ss[i]) << endl;
		kur[i] ^= 1;
		kie[kur[i]]++;
	}

	bool temppp[200000] = {};
	set<int> laisv[2];
	set<int> perkel[2];
	vector<string> reik[2];

	for (int i = 1; i <= kie[0]; i++)
		laisv[0].insert(i);

	for (int i =  kie[0] + 1; i <= kie[0] + kie[1]; i++)
		laisv[1].insert(i);

	for (int i = 0; i < n; i++) {
		if (isnumber(ss[i])) {
			int num = stoi(ss[i]);

			if (0 <= num and num < 200000)
				temppp[num] = true;

			if (1 <= num and num <= kie[0]) {
				if (kur[i] == 1)
					perkel[0].insert(num);

				laisv[0].erase(num);
			}
			else if (kie[0] < num and num <= kie[0] + kie[1]) {
				if (kur[i] == 0)
					perkel[1].insert(num);

				laisv[1].erase(num);
			}
			else
				reik[kur[i]].push_back(ss[i]);
		}
		else
			reik[kur[i]].push_back(ss[i]);
	}

	/*
		for (auto && x : perkel[0])
			cout << x << " ";

		cout << endl;

		for (auto && x : perkel[1])
			cout << x << " ";

		cout << endl;

		for (auto && x : laisv[0])
			cout << x << " ";

		cout << endl;

		for (auto && x : laisv[1])
			cout << x << " ";

		cout << endl;

		for (auto && x : reik[1])
			cout << x << " ";

		cout << endl;
		cout << "\\\\\n";*/

	string temp;

	for (int i = 1; i < 200000; i++) {
		if (!temppp[i]) {
			temp = to_string(i);
			break;
		}
	}

	int ej = 0;
	stringstream output;

	if (laisv[0].size() + laisv[1].size() == 0 and perkel[0].size() + perkel[1].size() + reik[0].size() + reik[1].size() > 0) {
		if (perkel[0].size() > 0) {
			output << "move " << *perkel[0].begin() << " " << temp << "\n";
			laisv[0].insert(*perkel[0].begin());
			reik[1].push_back(temp);
			perkel[0].erase(perkel[0].begin());
			ej++;
		}
		else {
			output << "move " << *perkel[1].begin() << " " << temp << "\n";
			laisv[1].insert(*perkel[1].begin());
			reik[0].push_back(temp);
			perkel[1].erase(perkel[1].begin());
			ej++;
		}
	}

	while (true) {
		if (laisv[1].size() > 0 and perkel[0].size() > 0) {
			output << "move " << *perkel[0].begin() << " " << *laisv[1].begin() << "\n";
			laisv[1].erase(laisv[1].begin());
			laisv[0].insert(*perkel[0].begin());
			perkel[0].erase(perkel[0].begin());
			ej++;
		}
		else if (laisv[0].size() > 0 and perkel[1].size() > 0) {
			output << "move " << *perkel[1].begin() << " " << *laisv[0].begin() << "\n";
			laisv[0].erase(laisv[0].begin());
			laisv[1].insert(*perkel[1].begin());
			perkel[1].erase(perkel[1].begin());
			ej++;
		}
		else
			break;
	}

	for (auto && x : reik[0]) {
		output << "move " << x << " " << *laisv[0].begin() << "\n";
		laisv[0].erase(laisv[0].begin());
		ej++;
	}

	for (auto && x : reik[1]) {
		output << "move " << x << " " << *laisv[1].begin() << "\n";
		laisv[1].erase(laisv[1].begin());
		ej++;
	}

	cout << ej << "\n";
	cout << output.str();


	return 0;
}