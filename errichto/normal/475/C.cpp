#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define st first
#define nd second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
const int inf=1e9+5, nax=1e3+5;

char sl[nax][nax];
int H, W;
int szer, wys;
int xx, yy;
pii start;
int res = inf;

bool vis[nax][nax];

pii Start() {
	RE(y, H) RE(x, W) if(sl[y][x] == 'X') return mp(x, y);
	return mp(0, 0);
}

bool Move() {
	if(sl[start.second][start.first + szer] == 'X') {
		for(int y = start.second; y <= start.second + wys - 1; ++y)
			vis[start.first + szer][y] = true;
		start.first++;
		return true;
	}
	if(sl[start.second + wys][start.first] == 'X') {
		for(int x = start.first; x <= start.first + szer - 1; ++x)
			vis[x][start.second + wys] = true;
		start.second++;
		return true;
	}
	return false;
}

void Rozwaz() {
	//cout << wys << " " << szer << "\n";
	pii memo = start;
	RE(x, W) RE(y, H) vis[x][y] = false;
	for(int x = start.first; x <= start.first + szer - 1; ++x)
		for(int y = start.second; y <= start.second + wys - 1; ++y)
			vis[x][y] = true;
	
	while(Move());
	
	start = memo;
	
	RE(x, W) RE(y, H) if((sl[y][x] == 'X') != vis[x][y]) {
		return;
	}
	mini(res, szer * wys);
}

void ZnajdzPara() {
	for(int y = start.second; y <= yy; ++y) if(sl[y][xx + 1] == 'X') {
		szer = xx - start.first + 1;
		wys = yy - y + 1;
		Rozwaz();
		break;
	}
	for(int x = start.first; x <= xx; ++x) if(sl[yy + 1][x] == 'X') {
		szer = xx - x + 1;
		wys = yy - start.second + 1;
		Rozwaz();
		break;
	}
	szer = xx - start.first + 1;
	wys = yy - start.second + 1;
	int memo = szer;
	szer = 1;
	Rozwaz();
	szer = memo;
	wys = 1;
	Rozwaz();
}

int main()
{
	ios_base::sync_with_stdio(0);

	cin >> H >> W;
	RE(y, H) {
		cin >> sl[y];
		sl[y][W] = '.';
	}
	RE(x, W + 2) sl[H][x] = '.';
	
	start = Start();
	//cout << start.first << " " << start.second << "\n";
	xx = start.first;
	while(xx + 1 < W && sl[start.second][xx + 1] == 'X') xx++;
	yy = start.second;
	while(yy + 1 < H && sl[yy + 1][start.first] == 'X') yy++;
	//cout << xx << " " << yy << "\n";
	ZnajdzPara();
	//cout << wys << " " << szer << "\n";
	
	if(res == inf) res = -1;
	cout << res;
	return 0;
}