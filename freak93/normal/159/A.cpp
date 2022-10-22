#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
	int N, D; 
	cin >> N >> D;

	map<string, map<string, int> > lastMessage;
	map<string, map<string, bool> > friends;

	vector < pair< pair<string, string>, int> > remember;
	int lastTime = 0;
	for (int i = 0; i < N; ++i) {
		string first, second;
		int time; 
		cin >> first >> second >> time;	
		time += D + 1; // so we can compare to 0(no message sent) and see that the diference is bigger than D

		if (time != lastTime) {
			for (auto &it: remember)
				lastMessage[it.first.first][it.first.second] = it.second;
			remember.clear();
		}
		
		remember.push_back(make_pair(make_pair(first, second), time));

		if (friends[first][second] == false) {
			if (lastMessage[second][first] >= time - D) {
				friends[first][second] = friends[second][first] = true;
			}
		}

		lastTime = time;
	}

	vector<string> answer;
	for(auto it = friends.begin(); it != friends.end(); ++it)
		for (auto jt = it -> second.begin(); jt != it -> second.end(); ++jt)
			if (jt -> second == true && (it -> first) < (jt -> first))
				answer.push_back((it -> first) + " " + (jt -> first));
	
	cout << answer.size() << "\n";
	for (auto it = answer.begin(); it != answer.end(); ++it)
		cout << *it << "\n";
}