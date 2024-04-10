import java.util.List;
import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] argv) {
        Scanner input = new Scanner(System.in);

        int N = input.nextInt(), M = input.nextInt(), D = input.nextInt();

        Graph G = new Graph(N, D);

        for (int i = 0; i < M; ++i) {
            int bad = input.nextInt();
            G.setBad(bad - 1);
        }

        for (int i = 1; i < N; ++i) {
            int from = input.nextInt(), to = input.nextInt();
            G.addEdge(from - 1, to - 1);
        }

        System.out.println(G.possibleCursed());
    }
}

class Graph {
    public Graph(int size_, int maxDistance_) {
        size = size_;
        maxDistance = maxDistance_;

        nodes = new Node[size];
        for (int i = 0; i < size; ++i)
            nodes[i] = new Node();
    }

    public void setBad(int who) {
        nodes[who].bad = true;
    }

    public void addEdge(Integer from, Integer to) {
        nodes[from].addEdge(nodes[to]);
    }

    public int possibleCursed() {
        dfsGetFarthestDown(nodes[0]);

        for (Node x : nodes)
            x.marked = false;

        dfsGetFarthestUp(nodes[0]);

        int Answer = 0;
        for (Node x : nodes)
            if (x.farthest() <= maxDistance)
                ++Answer;
        return Answer;
    }

    private void dfsGetFarthestDown(Node current) {
        current.marked = true;

        if (current.bad)
            current.farthestDown = 0;

        for (Node neighbour : current.neighbours())
            if (!neighbour.marked) {
                dfsGetFarthestDown(neighbour);
                current.farthestDown = Math.max(current.farthestDown, neighbour.farthestDown + 1);
            }
    }

    private void dfsGetFarthestUp(Node current) {
        current.marked = true;

        if (current.bad)
            current.farthestUp = Math.max(current.farthestUp, 0);

        Pair bestSoFar = new Pair(Integer.MIN_VALUE, Integer.MIN_VALUE);

        for (Node neighbour : current.neighbours())
            if (!neighbour.marked)
                bestSoFar.optimize(neighbour.farthestDown);

        for (Node neighbour : current.neighbours())
            if (!neighbour.marked) {
                neighbour.farthestUp = Math.max(bestSoFar.getDifferent(neighbour.farthestDown) + 2, current.farthestUp + 1);
                dfsGetFarthestUp(neighbour);
            }
    }

    private class Node {
        public Node() {
            bad = false;
            farthestDown = farthestUp = Integer.MIN_VALUE;
            marked = false;

            edges = new ArrayList<Node>();
        }

        public void addEdge(Node that) {
            edges.add(that);
            that.edges.add(this);
        }

        public List<Node> neighbours() {
            return edges;
        }

        public int farthest() {
            return Math.max(farthestDown, farthestUp);
        }

        public boolean bad;
        public int farthestDown;
        public int farthestUp;
        public boolean marked;
        private List<Node> edges;
    }

    private class Pair {
        public Pair(int first_, int second_) {
            first = first_;
            second = second_;
        }

        public void optimize(int newValue) {
            if (newValue > first) {
                second = first;
                first = newValue;
            } else if (newValue > second) {
                second = newValue;
            }
        }

        public int getDifferent(int value) {
            if (value == first)
                return second;
            return first;
        }

        private int first, second;
    }

    private int size;
    private int maxDistance;

    private Node[] nodes;
}