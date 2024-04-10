#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <forward_list>

using namespace std;

const int kMaxValue = 1000 * 1000 * 1000;

class Interval {
  public:
    Interval(const int &_x = 0, const int &_y = 0, const int &_index  = 0):
            x(_x), y(_y), index(_index) {
    }

    bool operator<(const Interval& that) const {
        if (x != that.x)
            return x < that.x;
        return y > that.y;
    }

    bool operator>(const int &that) const {
        return x < that and that < y;
    }

    bool operator>>(const Interval& that) const {
        if (x < that.x and that.x < y)
            return true;
        if (x < that.y and that.y < y)
            return true;
        return false;
    }

    int x, y, index;
};

forward_list<Interval> unite(forward_list<Interval> first, const forward_list<Interval>& second) {
    first.insert_after(first.before_begin(), second.begin(), second.end());
    return first;
}

class IntervalTree {
  public:
    IntervalTree(const int &lower_bound, const int &upper_bound):
            lower_bound_(lower_bound),
            upper_bound_(upper_bound),
            root_(new Node) {
    }

    void addInterval(const Interval& that) {
        Node *current = root_;
        int left = lower_bound_;
        int right = upper_bound_;

        do {
            int mid = (left + right) / 2;
            if (that.x <= mid and that.y > mid) { // we intersect
                current -> intervals.insert(that);
                break;
            }

            if (that.y <= mid) {
                right = mid;
                current = get(current -> left);
            } else {
                left = mid + 1;
                current = get(current -> right);
            }
        } while (true);
    }

    forward_list<Interval> intervalsAt(const int &where) {
        forward_list<Interval> result;
        Node *current = root_;
        int left = lower_bound_, right = upper_bound_;

        do {
            while (current -> intervals.size()) {
                auto biggest = *(current->intervals.begin());
                if (biggest > where) {
                    result.push_front(biggest);
                    current->intervals.erase(current->intervals.begin());
                    continue;
                }
                break;
            }

            int mid = (left + right) / 2;
            if (where <= mid) {
                if (not (current = current -> left))
                    return result;
                right = mid;
            } else {
                if (not (current = current -> right))
                    return result;
                left = mid + 1;
            }
        } while (true);
    }

  private:
    class Node {
      public:
        Node():
                left(nullptr),
                right(nullptr) {
        }

        multiset<Interval> intervals;
        Node *left, *right;
    };

    Node* get(Node * & now) const {
        if (now == nullptr)
            now = new Node;
        return now;
    }

    int lower_bound_, upper_bound_;
    Node* root_;
};

class DisjointSet {
  public:
    DisjointSet(const int &size = 1):
            group_(size) {
        for (int i = 0; i < size; ++i)
            group_[i] = i;
    }

    int group(int index) {
        if (group_[index] == index)
            return index;
        return (group_[index] = group(group_[index]));
    }

    void merge(int first, int second) {
        if (rand() % 2)
            swap(first, second);

        first = group(first);
        group_[first] = group(second);
    }

  private:
    vector<int> group_;
};

int main() {
    int N; cin >> N;

    DisjointSet D(N);
    IntervalTree I(-kMaxValue, +kMaxValue);

    int current_interval = 0;
    vector<Interval> past_intervals(N), present_intervals(N);
    for (int i = 0; i < N; ++i) {
        int type, x, y;
        cin >> type >> x >> y;

        if (type == 1) {
            past_intervals[current_interval] = {x, y, 0};
            auto old_intervals = unite(I.intervalsAt(x), I.intervalsAt(y));

            int newX = x, newY = y;
            for (auto &interval : old_intervals) {
                D.merge(current_interval, interval.index);
                newX = min(newX, interval.x);
                newY = max(newY, interval.y);
            }

            present_intervals[D.group(current_interval)] = {newX, newY, 0};

            I.addInterval({newX, newY, D.group(current_interval++)});
        } else {
            if (D.group(x - 1) == D.group(y - 1))
                cout << "YES\n";
            else {
                x = x - 1;
                y = D.group(y - 1);
                if (present_intervals[y] >> past_intervals[x])
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        }
    }
}