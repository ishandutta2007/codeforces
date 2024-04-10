#pragma GCC optimize("O3")

#include <ctime>
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

mt19937 rnd(time(nullptr));

const int INF = 1e9;

struct Treap {
    struct Node {
        int x;
        int y;
        Node* l;
        Node* r;
        int size;

        explicit Node(int value) {
            x = value;
            y = rnd();
            l = nullptr;
            r = nullptr;
            size = 1;
        }

        static int GetSize(Node* node) {
            if (!node) {
                return 0;
            }
            return node->size;
        }

        static void Upd(Node* node) {
            if (!node) {
                return;
            }
            node->size = 1 + GetSize(node->l) + GetSize(node->r);
        }

        static Node* Merge(Node* l, Node* r) {
            if (!l) {
                return r;
            }
            if (!r) {
                return l;
            }
            if (l->y > r->y) {
                l->r = Merge(l->r, r);
                Upd(l);
                return l;
            } else {
                r->l = Merge(l, r->l);
                Upd(r);
                return r;
            }
        }

        static pair<Node*, Node*> SplitByValue(Node* node, int x) {
            if (!node) {
                return {};
            }
            if (node->x <= x) {
                pair<Node*, Node*> tmp = SplitByValue(node->r, x);
                node->r = tmp.first;
                Upd(node);
                return {node, tmp.second};
            } else {
                pair<Node*, Node*> tmp = SplitByValue(node->l, x);
                node->l = tmp.second;
                Upd(node);
                return {tmp.first, node};
            }
        }

        static void Insert(Node*& root, int x) {
            pair<Node*, Node*> tmp = SplitByValue(root, x);
            Node* new_node = new Node(x);
            root = Merge(tmp.first, Merge(new_node, tmp.second));
        }

        static void Erase(Node*& root, int l, int r) {
            pair<Node*, Node*> tmp1 = SplitByValue(root, l - 1);
            pair<Node*, Node*> tmp2 = SplitByValue(tmp1.second, r);
            root = Merge(tmp1.first, tmp2.second);
        }

        static void Print(Node* node) {
            if (!node) {
                return;
            }
            Print(node->l);
            cout << node->x << " ";
            Print(node->r);
        }

        static int GetFromLToR(Node*& node, int l, int r) {
            if (!node) {
                return 0;
            }
            pair<Node*, Node*> tmp1 = SplitByValue(node, l - 1);
            pair<Node*, Node*> tmp2 = SplitByValue(tmp1.second, r);
            int ans = GetSize(tmp2.first);
            node = Merge(tmp1.first, Merge(tmp2.first, tmp2.second));
            return ans;
        }

        static pair<int, int> LowerAndBigger(Node*& node, int x) {
            pair<Node*, Node*> tmp1 = SplitByValue(node, x - 1);
            pair<Node*, Node*> tmp2 = SplitByValue(tmp1.second, x);
            pair<int, int> res = {-INF, INF};
            {
                Node* cur = tmp1.first;
                if (cur) {
                    while (cur->r) {
                        cur = cur->r;
                    }
                    res.first = cur->x;
                }
            }
            {
                Node* cur = tmp2.second;
                if (cur) {
                    while (cur->l) {
                        cur = cur->l;
                    }
                    res.second = cur->x;
                }
            }
            node = Merge(tmp1.first, Merge(tmp2.first, tmp2.second));
            return res;
        }
    };

    Node* root;

    explicit Treap(int n) {
        root = nullptr;
        for (int i = 0; i < n; ++i) {
            Insert(i);
        }
    }

    void Insert(int value) {
        Node::Insert(root, value);
    }

    void Erase(int l, int r) {
        Node::Erase(root, l, r);
    }

    int GetFromLRoR(int l, int r) {
        return Node::GetFromLToR(root, l, r);
    }

    void Print() const {
        Node::Print(root);
        cout << endl;
    }

    pair<int, int> LowerAndBigger(int x) {
        return Node::LowerAndBigger(root, x);
    }
};

struct Treap2 {
    struct Node2 {
        int x;
        int y;
        int value;
        Node2* l;
        Node2* r;
        int size;
        int min_value;

        explicit Node2(int left, int right) {
            x = left;
            y = rnd();
            l = nullptr;
            r = nullptr;
            size = 1;
            value = min_value = right;
        }

        static int GetSize(Node2* node) {
            if (!node) {
                return 0;
            }
            return node->size;
        }

        static int GetMinValue(Node2* node) {
            if (!node) {
                return INF;
            }
            return node->min_value;
        }

        static void Upd(Node2* node) {
            if (!node) {
                return;
            }
            node->size = 1 + GetSize(node->l) + GetSize(node->r);
            node->min_value = min({GetMinValue(node->l), GetMinValue(node->r), node->value});
        }

        static Node2* Merge(Node2* l, Node2* r) {
            if (!l) {
                return r;
            }
            if (!r) {
                return l;
            }
            if (l->y > r->y) {
                l->r = Merge(l->r, r);
                Upd(l);
                return l;
            } else {
                r->l = Merge(l, r->l);
                Upd(r);
                return r;
            }
        }

        static pair<Node2*, Node2*> SplitByValue(Node2* node, int x) {
            if (!node) {
                return {};
            }
            if (node->x <= x) {
                pair<Node2*, Node2*> tmp = SplitByValue(node->r, x);
                node->r = tmp.first;
                Upd(node);
                return {node, tmp.second};
            } else {
                pair<Node2*, Node2*> tmp = SplitByValue(node->l, x);
                node->l = tmp.second;
                Upd(node);
                return {tmp.first, node};
            }
        }

        static void Insert(Node2*& root, int l, int r) {
            pair<Node2*, Node2*> tmp = SplitByValue(root, l);
            auto* new_node = new Node2(l, r);
            root = Merge(tmp.first, Merge(new_node, tmp.second));
        }

        static void Erase(Node2*& root, int l, int r) {
            pair<Node2*, Node2*> tmp1 = SplitByValue(root, l - 1);
            pair<Node2*, Node2*> tmp2 = SplitByValue(tmp1.second, r);
            root = Merge(tmp1.first, tmp2.second);
        }

        static void Print(Node2* node) {
            if (!node) {
                return;
            }
            Print(node->l);
            cout << "(" << node->x << "," << node->value << ")";
            Print(node->r);
        }

        static int GetFromLToR(Node2*& node, int l, int r) {
            if (!node) {
                return 0;
            }
            pair<Node2*, Node2*> tmp1 = SplitByValue(node, l - 1);
            pair<Node2*, Node2*> tmp2 = SplitByValue(tmp1.second, r);
            int ans = GetSize(tmp2.first);
            node = Merge(tmp1.first, Merge(tmp2.first, tmp2.second));
            return ans;
        }

        static int GetMin(Node2*& node, int l, int r) {
            pair<Node2*, Node2*> tmp1 = SplitByValue(node, l - 1);
            pair<Node2*, Node2*> tmp2 = SplitByValue(tmp1.second, r);
            int ans = GetMinValue(tmp2.first);
            node = Merge(tmp1.first, Merge(tmp2.first, tmp2.second));
            return ans;
        }
    };

    Node2* root;

    explicit Treap2(Node2* node) {
        root = node;
    }

    void Insert(int l, int r) {
        Node2::Insert(root, l, r);
    }

    void Erase(int l, int r) {
        Node2::Erase(root, l, r);
    }

    int GetFromLRoR(int l, int r) {
        return Node2::GetFromLToR(root, l, r);
    }

    int GetMin(int l, int r) {
        return Node2::GetMin(root, l, r);
    }

    void Print() const {
        Node2::Print(root);
        cout << endl;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    Treap treap(n);
    Treap2 treap2(nullptr);
    // treap.Print();
    vector<pair<int, int>> queries;
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r, x;
            cin >> l >> r >> x;
            if (x == 0) {
                --l, --r;
                treap.Erase(l, r);
            } else {
                --l, --r;
                queries.emplace_back(l, r);
                treap2.Insert(l, r);
            }
        }
        if (t == 1) {
            int pos;
            cin >> pos;
            --pos;
            if (treap.GetFromLRoR(pos, pos) == 0) {
                cout << "NO\n";
            } else {
                // bool ill = false;
                pair<int, int> kek = treap.LowerAndBigger(pos);
                // cout << kek.first << " " << kek.second << endl;
                int lul = treap2.GetMin(kek.first + 1, kek.second - 1);
                // cout << lul << endl;
                if (lul <= kek.second - 1) {
                    cout << "YES\n";
                } else {
                    cout << "N/A\n";
                }
                /*
                for (auto& now : queries) {
                    int l = now.first;
                    int r = now.second;
                    if (l <= pos && pos <= r) {
                        if (treap.GetFromLRoR(l, r) == 1) {
                            ill = true;
                        }
                    }
                }
                if (ill) {
                    cout << "YES\n";
                } else {
                    cout << "N/A\n";
                }
                 */
            }
        }
        // treap.Print();
    }
    return 0;
}