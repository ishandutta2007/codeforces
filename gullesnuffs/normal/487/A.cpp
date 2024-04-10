#include <bits/stdc++.h>

using namespace std;

bool win(int hp1, int atk1, int def1, int hp2, int atk2, int def2){
	if(atk2 <= def1)
		return 0;
	if(atk1 <= def2)
		return 1;
	int turns1=(hp1+atk2-def1-1)/(atk2-def1);
	int turns2=(hp2+atk1-def2-1)/(atk1-def2);
	return (turns2>turns1);
}

int main(){
	int hp1, hp2, atk1, atk2, def1, def2;
	cin >> hp2 >> atk2 >> def2;
	cin >> hp1 >> atk1 >> def1;
	int h, a, d;
	cin >> h >> a >> d;
	int best=100*(h+a+d);
	for(int i=0; i*h < best; ++i)
		for(int j=0; i*h+j*a < best; ++j)
			for(int k=0; i*h+j*a+k*d < best; ++k){
				if(win(hp1, atk1, def1, hp2+i, atk2+j, def2+k)){
					best=min(best, i*h+j*a+k*d);
				}
			}
	cout << best << endl;
}