fun main() {
    repeat (readLine()!!.toInt()) {
        println(readLine()!!.split(' ').map(String::toInt).sum())
    }
}