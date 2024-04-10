#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

pair<int, int> volc[100005];
vector<pair<int, int> > events;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        volc[i] = make_pair(x, y);
    }
    sort(volc, volc + m);
    events.push_back(make_pair(0, 1));
    events.push_back(make_pair(1, 0));
    int lastY = -1;
    for (int i = 0; i < m; ){
        if (volc[i].first != lastY + 1){
            vector<pair<int, int> > vii;
            vii.push_back(events[0]);
            vii.push_back(make_pair(n, 0));
            events = vii;
        }
        lastY = volc[i].first;
        int j;
        for (j = i; j < m && volc[j].first == volc[i].first; ++j){
            events.push_back(make_pair(volc[j].second, 2));
        }
        events.push_back(make_pair(n, 2));
        sort(events.begin(), events.end());
        vector<pair<int, int> > newEvents;
        bool last = 0;
        bool doNext = 0;
        int lastPos;
        for (int k = 0; k < events.size(); ++k){
            if (events[k].second == 0){
                if (events[k].first <= lastPos)
                    doNext = 0;
                last = 0;
            }
            else if (events[k].second == 1){
                last = 1;
                if(!doNext)
                    lastPos = events[k].first;
                doNext = true;
            }
            else{
                if (doNext){
                    if (lastPos < events[k].first){
                        newEvents.push_back(make_pair(lastPos, 1));
                        newEvents.push_back(make_pair(events[k].first, 0));
                    }
                    lastPos = events[k].first + 1;
                }
                if (!last)
                    doNext = false;
            }
        }
        events = newEvents;
        i = j;
        if (events.empty())
            break;
    }
    if ((events.size() > 1 && events[events.size() - 2].first < n && events[events.size() - 1].first == n)||
        (lastY < n-1 && events.size() > 1)){
        printf("%d\n", 2 * n - 2);
    }
    else
        printf("-1\n");
    return 0;
}