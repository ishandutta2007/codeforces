#ifdef __GNUC__
#pragma GCC target("sse4,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <array>
#include <iterator>

template<int Size, int Start = 0>
struct Alphabet {
    static constexpr int size = Size;
    static constexpr int start = Start;
};

using Latin = Alphabet<26, 'a'>;


struct SuffixTreeOptions {
    static constexpr int Search = 1;
    static constexpr int Weights = 2;
};
template<class alphabet, class Weight = int>
struct SuffixTree {
    struct BasicNode {
        uint32_t up = 0;
        uint32_t len = 0;
        Weight weight = 0;
        std::array<uint32_t, alphabet::size> link = {};
    };
    struct SearchNode {
        uint32_t idx = 0;
        std::array<uint32_t, alphabet::size> children = {};
    };
    std::vector<Weight> weights;
    std::vector<BasicNode> nodes;
    std::vector<SearchNode> searchNodes;
    std::vector<uint32_t> original;

    template<class T>
    void setWeights(T&& weights) {
        this->weights = std::forward<T>(weights);
    }

    template<int flags = 0, class T>
    void buildTree(const T& s) {
        nodes.clear();
        if (flags & SuffixTreeOptions::Search) {
            searchNodes.clear();
            searchNodes.resize(2);
            original.resize(s.size());
        }
        nodes.resize(2);
        uint32_t prev = 1;
        for (size_t idx = s.size(); idx-- > 0;) {
            uint32_t letter = s[idx] - alphabet::start;
            if (flags & SuffixTreeOptions::Search) {
                original[idx] = letter;
            }
            uint32_t curNode = static_cast<uint32_t>(nodes.size());
            nodes.emplace_back();
            if (flags & SuffixTreeOptions::Search) {
                searchNodes.emplace_back();
                searchNodes.back().idx = idx;
            }
            if (flags & SuffixTreeOptions::Weights) {
                nodes[curNode].weight = weights.empty() ? 1 : weights[idx];
            }
            nodes[curNode].len = nodes[prev].len + 1;
            for (; prev != 0 && nodes[prev].link[letter] == 0; prev = nodes[prev].up) {
                nodes[prev].link[letter] = curNode;
            }
            if (prev == 0) {
                nodes[curNode].up = 1;
                if (flags & SuffixTreeOptions::Search) {
                    searchNodes[1].children[letter] = curNode;
                }
            } else {
                int sibling = nodes[prev].link[letter];
                if (nodes[sibling].len == nodes[prev].len + 1) {
                    nodes[curNode].up = sibling;
                    if (flags & SuffixTreeOptions::Search) {
                        searchNodes[sibling].children[original[nodes[sibling].len + idx]] = curNode;
                    }
                } else {
                    uint32_t branch = static_cast<uint32_t>(nodes.size());
                    nodes.emplace_back();
                    if (flags & SuffixTreeOptions::Search) {
                        searchNodes.emplace_back();
                        searchNodes.back().idx = idx;
                    }
                    nodes[branch].len = nodes[prev].len + 1;
                    std::copy(nodes[sibling].link.begin(), nodes[sibling].link.end(), nodes[branch].link.begin());
                    nodes[branch].up = nodes[sibling].up;
                    nodes[sibling].up = branch;
                    nodes[curNode].up = branch;
                    if (flags & SuffixTreeOptions::Search) {
                        searchNodes[branch].children[original[nodes[branch].len + idx]] = curNode;
                        searchNodes[branch].children[original[nodes[branch].len + searchNodes[sibling].idx]] = sibling;
                        searchNodes[nodes[branch].up].children[original[nodes[nodes[branch].up].len + idx]] = branch;
                    }
                    for (; nodes[prev].link[letter] == sibling; prev = nodes[prev].up) {
                        nodes[prev].link[letter] = branch;
                    }
                }
            }
            prev = curNode;
        }
        if (flags & SuffixTreeOptions::Weights) {
            std::vector<uint32_t> count(s.size() + 1);
            for (size_t i = 1; i < nodes.size(); i++) {
                count[nodes[i].len]++;
            }
            for (size_t i = 1; i < count.size(); i++) {
                count[i] += count[i - 1];
            }
            std::vector<uint32_t> order(nodes.size());
            for (size_t i = 1; i < nodes.size(); i++) {
                uint32_t& pos = count[nodes[i].len];
                pos--;
                order[pos] = static_cast<uint32_t>(i);
            }
            for (size_t i = order.size(); i-- > 0;) {
                nodes[nodes[order[i]].up].weight += nodes[order[i]].weight;
            }
        }
    }

    template<class T>
    std::pair<Weight, size_t> find(const T& s) {
        uint32_t node = 1;
        uint32_t idx = 0;
        Weight res = nodes[node].weight;
        for (size_t i = 0; i < s.size(); i++) {
            int letter = s[i] - alphabet::start;
            if (i == nodes[node].len) {
                if (searchNodes[node].children[letter] == 0) {
                    return {res, i};
                }
                node = searchNodes[node].children[letter];
                res = nodes[node].weight;
                idx = searchNodes[node].idx;
            }
            if (letter != original[idx + i]) {
                return {res, i};
            }
        }
        return {res, s.size()};
    }
};

struct Solution {
    std::string s;
    std::string allowed;

    void run(std::istream& in, std::ostream& out) {
        int n;
        in >> n;
        in >> s;
        in >> allowed;
        std::reverse(s.begin(), s.end());
        std::reverse(allowed.begin(), allowed.end());
        std::vector<int> weights;
        for (char c : allowed) {
            weights.push_back(1 - (c - '0'));
        }
        SuffixTree<Latin> tree;
        tree.setWeights(weights);
        tree.buildTree<SuffixTreeOptions::Weights>(s);
        int64_t ans = 0;
        for (const auto& node : tree.nodes) {
            ans = std::max<int64_t>(ans, node.len * (int64_t) node.weight);
        }
        out << ans << std::endl;
    }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}