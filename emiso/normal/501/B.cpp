#include <bits/stdc++.h>

using namespace std;

map<string,string> mapa,maparev;

int main() {
    string old,_new;
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin.ignore();
        cin >> old >> _new;

        if(mapa.find(old) == mapa.end() && maparev.find(old) == maparev.end()) {
            mapa.insert(make_pair(old,_new));
            maparev.insert(make_pair(_new,old));
        }
        else {
            string original = maparev[old];
            mapa[original] = _new;
            maparev[_new] = original;
        }
    }

    cout << mapa.size() << endl;
    for(map<string,string>::iterator it = mapa.begin();it!=mapa.end();it++) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}